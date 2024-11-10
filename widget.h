#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<stack>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_one_clicked();

    void on_two_clicked();

    void on_three_clicked();

    void on_four_clicked();

    void on_five_clicked();

    void on_six_clicked();

    void on_seven_clicked();

    void on_eight_clicked();

    void on_nine_clicked();

    void on_zore_clicked();

    void on_left_clicked();

    void on_right_clicked();

    void on_chu_clicked();

    void on_mul_clicked();

    void on_add_clicked();

    void on_sub_clicked();

    void on_eqaul_clicked();

    void on_delete_2_clicked();

    void on_clear_clicked();

private:
    Ui::Widget *ui;
    QString expression;
    std::stack<int> num;
    std::stack<QChar> op;
    std::map<QChar,int> mp={ {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };
    void eval();

};
#endif // WIDGET_H
