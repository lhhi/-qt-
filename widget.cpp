#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    ui->setupUi(this);
    this->setMaximumSize(180,250);
    this->setMinimumSize(180,250);
    this->setWindowTitle("计算器");

    QFont f("仿宋",14);
    ui->mainlineEdit->setFont(f);

    QIcon con("F:\\qtonline\\calcaul\\屏幕截图 2024-11-10 111051.png");
    ui->clear->setIcon(con);

    ui->eqaul->setStyleSheet("background:orange");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_one_clicked()
{
    expression +='1';
    ui->mainlineEdit->setText(expression);
}


void Widget::on_two_clicked()
{
    expression +='2';
    ui->mainlineEdit->setText(expression);
}


void Widget::on_three_clicked()
{
    expression +='3';
    ui->mainlineEdit->setText(expression);
}


void Widget::on_four_clicked()
{
    expression +='4';
    ui->mainlineEdit->setText(expression);
}


void Widget::on_five_clicked()
{
    expression +='5';
    ui->mainlineEdit->setText(expression);
}


void Widget::on_six_clicked()
{
    expression +='6';
    ui->mainlineEdit->setText(expression);
}


void Widget::on_seven_clicked()
{
    expression +='7';
    ui->mainlineEdit->setText(expression);
}


void Widget::on_eight_clicked()
{
    expression +='8';
    ui->mainlineEdit->setText(expression);
}


void Widget::on_nine_clicked()
{
    expression +='9';
    ui->mainlineEdit->setText(expression);
}


void Widget::on_zore_clicked()
{
    expression +='0';
    ui->mainlineEdit->setText(expression);
}




void Widget::on_left_clicked()
{
    expression +='(';
    ui->mainlineEdit->setText(expression);
}


void Widget::on_right_clicked()
{
    expression +=')';
    ui->mainlineEdit->setText(expression);
}



void Widget::on_chu_clicked()
{
    expression +='/';
    ui->mainlineEdit->setText(expression);
}


void Widget::on_mul_clicked()
{
    expression +='*';
    ui->mainlineEdit->setText(expression);
}


void Widget::on_add_clicked()
{
    expression +='+';
    ui->mainlineEdit->setText(expression);
}


void Widget::on_sub_clicked()
{
    expression +='-';
    ui->mainlineEdit->setText(expression);
}

void Widget::eval(){
    int second=num.top();
    num.pop();
    int first=num.top();
    num.pop();
    QChar operater=op.top();
    op.pop();
    int result;
    if(operater=='*')result=first*second;
    else if(operater=='/') result=first/second;
    else if(operater=='-') result=first-second;
    else if(operater=='+') result=first+second;
    num.push(result);
}

void Widget::on_eqaul_clicked()
{

    while(!num.empty()) num.pop();
    while(!op.empty()) op.pop();
    for(int i=0;i<expression.size();i++){
        QChar token = expression[i];
        if(token=='*'||token=='/'||token=='+'||token=='-'){
            while(op.size()&&op.top()!='('&&mp[token]<=mp[op.top()]) eval();
            op.push(token);
        }else if(token=='('){
            op.push(token);
        }else if(token==')'){
            while(op.top()!='(') eval();
            op.pop();
        }else if(token>='0'&&token<='9'){
            int j=i,x=0;
            while(j<expression.size()&&expression[j]>='0'&&expression[j]<='9'){
                x=x*10+expression[j].digitValue();
                j++;
            }
            num.push(x);
            i=j-1;
        }
    }
    while(op.size()) eval();
    expression.clear();
    expression=QString::number(num.top());
    ui->mainlineEdit->setText(expression);
}


void Widget::on_delete_2_clicked()
{
    expression.clear();
    ui->mainlineEdit->clear();
}


void Widget::on_clear_clicked()
{
    expression.chop(1);
    ui->mainlineEdit->setText(expression);
}
