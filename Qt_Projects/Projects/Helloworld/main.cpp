#include <QApplication>
#include<QLabel>
int main(int argc, char* argv []){
    QApplication app (argc, argv);
    QLabel *label = new QLabel ("Hello World");
    label->setWindowTitle("MY APP");
    label->resize(500, 500);
    label->show();
    return app.exec();
}
