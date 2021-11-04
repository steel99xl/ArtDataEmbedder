#include "uwu.h"
#include "ui_uwu.h"

uwu::uwu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::uwu)
{
    ui->setupUi(this);
}

uwu::~uwu()
{
    delete ui;
}


void uwu::on_OpenButton_clicked()
{
    //QTextStream output(stdout);
    fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    //output << fileName;


    PixelMap.load(fileName);


    PixelMap.setDevicePixelRatio(PixelMap.width()/ui->ImageDisplay->width());
    ui->ImageDisplay->setPixmap(PixelMap);

    Image.load(fileName);

    ui->Description->setText(Image.text("Description"));
    ui->AuthorName->setText(Image.text("Author"));
    ui->CopyrightInfo->setText(Image.text("Copyright"));

    /*FilePath = fileName.toStdString();
    File.open(fileName.toStdString().c_str(), std::ios::in);
       if (File.is_open()) {
           Lines.clear();
           std::string line;
           while (getline(File, line)) {
               Lines.push_back(line);
           }
           File.close();

       } else {
           output << "ERROR";
       }

       */



    LoadedImage = new QFile(fileName);
    if ((LoadedImage->open(QIODevice::ReadWrite | QIODevice::Append))){


        LoadedImage->close();
    }


    FileLoaded = true;


}




void uwu::on_SaveButton_clicked()
{
    //QTextStream output(stdout);

    QString Author = ui->AuthorName->text();
    QString Description =  ui->Description->toPlainText();
    QString CopyRight = ui->CopyrightInfo->toPlainText();
    ImageWriter = new QImageWriter(fileName);
    ImageWriter->setText("Description",Description);
    ImageWriter->setText("Author",Author);
    ImageWriter->setText("Copyright", CopyRight);
    ImageWriter->write(Image);

    //Lines.push_back("\nArtDataEmbeder[");
    //Lines.push_back(Test.toStdString());
    //Lines.push_back("]");


}

