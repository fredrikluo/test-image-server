#include "imageviews.h"
#include <QApplication>
#include <QListWidget>
#include <QListWidgetItem>
#include <QIcon>

#include "loadimage.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageViews w;
    QListWidget *lw = w.findChild<QListWidget*>("listWidget");
    lw->setViewMode(QListWidget::IconMode);
    lw->setIconSize(QSize(200,200));
    lw->setResizeMode(QListWidget::Adjust);

    loadImage ldImage;
    vector<string>& images = ldImage.getImages();

    for (auto itr = images.begin(); itr != images.end(); ++itr) {
        lw->addItem(new QListWidgetItem(QIcon(itr->c_str()),""));
    }

    w.show();

    return a.exec();
}
