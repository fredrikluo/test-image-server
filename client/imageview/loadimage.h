#ifndef LOAD_IMAGE_H
# define LOAD_IMAGE_H

#include <vector>
#include <string>

class loadImage {
public:
    loadImage();
    virtual ~loadImage();

    std::vector<std::string>& getImages() {
        return m_images;
    }

private:
    std::vector<std::string> m_images;
};

#endif // LOAD_IMAGE_H
