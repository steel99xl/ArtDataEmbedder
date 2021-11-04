#ifndef UWU_H
#define UWU_H

#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
#include <QFile>
#include <QByteArray>
#include <QImageIOHandler>
#include <QImageWriter>


QT_BEGIN_NAMESPACE
namespace Ui { class uwu; }
QT_END_NAMESPACE

class uwu : public QMainWindow
{
    Q_OBJECT

public:
    uwu(QWidget *parent = nullptr);
    ~uwu();


private slots:
    void on_OpenButton_clicked();


    void on_SaveButton_clicked();

private:
    QPixmap PixelMap;
    QImage Image;
    QString fileName;
    bool FileLoaded;
    QFile *LoadedImage;
    QImageWriter *ImageWriter;
    Ui::uwu *ui;
};
#endif // UWU_H
