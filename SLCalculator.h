#pragma once

#include <QtWidgets/QWidget>
#include<QDebug>
#include<QDir>
#include<QTranslator>
#include<QMessageBox>
#include<Windows.h>
#include "ui_mainWindow.h"

struct POSDATA
{
    float throwPos_X;
    float throwPos_Y;
    float landingPos_X;
    float landingPos_Y;
};
struct ISEDITEDPOS
{
    bool tx;
    bool ty;
    bool lx;
};
struct INTERSECTIONPOSDATA
{
    UINT8 parPosData1_Num;
    UINT8 parPosData2_Num;
    float X;
    float Y;
};
struct RESULTPOSDATA
{
    float X;
    float Y;
    float errStatistics;
};

class MCSC : public QWidget
{
    Q_OBJECT

public:
    UINT8 nowInputedPos = 0;
    UINT16 lastErrStatistics = 0;
    ISEDITEDPOS isEditedPos = {};

    MCSC(QWidget *parent = Q_NULLPTR);

    void startBtnClicked(void);
    void nextInput(void);
    void goCalibration(void);
    void showResult(void);
    RESULTPOSDATA calculateSLPos(void);
    INTERSECTIONPOSDATA findIntersectionPos(UINT8 ,UINT8);
    void TX_Next(void) { ui.throwPos_Y->setFocus(); ui.throwPos_Y->selectAll(); isEditedPos.tx = true; checkEdit(); }
    void TY_Next(void) { isEditedPos.ty = true; checkEdit(); }
    void LX_Next(void) { ui.landingPos_Y->setFocus(); ui.landingPos_Y->selectAll(); isEditedPos.lx = true; checkEdit(); }
    void CTR1(void) { QMessageBox::information(this, "Translation", ui.pageInfoTitle_input->text()); }
    void CTR2(void) { QMessageBox::information(this, "Translation", ui.pageInfoTitle_calibration->text()); }
    void checkEdit(void)
    {
        if (isEditedPos.lx == true && isEditedPos.tx == true && isEditedPos.ty == true)
        {
            ui.pb_nextInput->setEnabled(true);
        }
    }
    void enumQmFile(void);
    void changeLanguage(int);
    void retranslateUi(void);
private:
    Ui::MCSCClass ui;
};
