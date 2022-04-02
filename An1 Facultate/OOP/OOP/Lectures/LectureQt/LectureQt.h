#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_LectureQt.h"

class LectureQt : public QMainWindow
{
    Q_OBJECT

public:
    LectureQt(QWidget *parent = Q_NULLPTR);

private:
    Ui::LectureQtClass ui;
};
