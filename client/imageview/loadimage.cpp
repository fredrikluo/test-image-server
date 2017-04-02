#include "loadimage.h"

#include <fstream>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/filesystem.hpp>

using boost::asio::ip::tcp;
using namespace std;

static const char * SERVER_IP = "127.0.0.1";
static const short PORT = 8080;
static const char MAGIC_HDR[] = "APP_DATA";

loadImage::loadImage() {
    boost::asio::io_service io_service;

    tcp::endpoint endpoint(boost::asio::ip::address::from_string(SERVER_IP), PORT);
    tcp::socket socket(io_service);
    socket.connect(endpoint);

    const std::string cmd = "GETALL\r";
    boost::array<char, 1024> buf;
    copy(cmd.begin(), cmd.end(), buf.begin());
    boost::system::error_code error;
    socket.write_some(boost::asio::buffer(buf, cmd.size()), error);

    std::vector<char> data;
    for (;;)
    {
        size_t len = socket.read_some(boost::asio::buffer(buf), error);
        if (error == boost::asio::error::eof)
            break;
        else if (error)
            throw boost::system::system_error(error);

        data.insert(data.end(), buf.begin(), buf.begin() + len);
    }

    // the start
    vector<char> magicHdr(MAGIC_HDR, MAGIC_HDR + sizeof(MAGIC_HDR));
    auto last = begin(data);
    static char fn[100];
    for (int n = 0;; n++) {
        auto res = search(last, end(data), begin(magicHdr), end(magicHdr));
        if (res != last) {
            vector<char> image(last, res);
            // save the image
            // now we have the data, save them
            snprintf(fn, sizeof(fn), "%d.jpg", n);
            ofstream fout(fn, ios::out | ios::binary);
            fout.write(&image[0], image.size());
            fout.close();
            m_images.push_back(std::string(fn));
        }

        last = res + magicHdr.size();
        if(res == end(data)) {
            break;
        }
    }
}

loadImage::~loadImage() {
    for (auto itr = m_images.begin(); itr != m_images.end(); ++itr) {
        boost::filesystem::remove(itr->c_str());
    }
}
