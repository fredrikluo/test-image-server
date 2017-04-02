#ifndef IMAGEVIEWS_H
#define IMAGEVIEWS_H

#include <QMainWindow>

namespace Ui {
class ImageViews;
}

class ImageViews : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImageViews(QWidget *parent = 0);
    ~ImageViews();

private:
    Ui::ImageViews *ui;
};

#endif // IMAGEVIEWS_H
