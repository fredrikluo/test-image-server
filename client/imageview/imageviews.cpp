#include "imageviews.h"
#include "ui_imageviews.h"

ImageViews::ImageViews(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImageViews)
{
    ui->setupUi(this);
}

ImageViews::~ImageViews()
{
    delete ui;
}
