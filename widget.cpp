#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Initializations
    srand(time(NULL));

    unknownNumber = rand();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_GuessButton_clicked()
{
    guess = ui -> numberBox -> value();

    qDebug() << "Number guessed: " << guess;

    if(guess < unknownNumber)
    {
        ui -> MessageBox -> setText("Guess higher!\n");
    }
    else if(guess > unknownNumber)
    {
        ui -> MessageBox -> setText("Guess lower!\n");
    }
    else
    {
        ui -> MessageBox -> setText("Congratulations!!!! You guessed\n"
                                    "the correct number " + QString::number(unknownNumber));


        //Set guessing to disabled since user guessed correctly
        ui -> GuessButton -> setDisabled(true);
    }
}

void Widget::on_StartOverButton_clicked()
{
    //RESET SPIN BOX
    //CHANGE NUMBER
    //CLEAR MESSAGE BOX
    //RE-ENABLE GUESS BUTTON
    ui -> numberBox -> setValue(0);
    unknownNumber = rand();
    ui -> MessageBox -> setText("");
    ui -> GuessButton -> setDisabled(false);
}
