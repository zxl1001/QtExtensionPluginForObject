/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    smmanagerview.h
 * @brief
 *******************************************************************************
 */
#ifndef BDSCHANNELONEVIEW_H
#define BDSCHANNELONEVIEW_H

#include "graphicsview.h"
#include <QDialog>

namespace Ui {
class BDSChannelOneView;
}

namespace BDSChannelOne {
enum class  ALGORITHM_TYPE : uint{
    ALGORITHM_1,
    ALGORITHM_2,
    ALGORITHM_3,
    ALGORITHM_4,
    ALGORITHM_5,
    ALGORITHM_6,
    ALGORITHM_7,
    ALGORITHM_8,
    ALGORITHM_9,
    ALGORITHM_10,
    ALGORITHM_11,
};

class BDSChannelOneView : public QDialog
{
    Q_OBJECT

public:
    explicit BDSChannelOneView(QWidget *parent = 0);
    ~BDSChannelOneView();

    void setPoints(const QVector<QPointF> &points);
    void setPixmap(const QPixmap &image);
Q_SIGNALS:
    void processData(ALGORITHM_TYPE, float);

private slots:
    void on_processBtn_clicked();

private:
    Ui::BDSChannelOneView *ui;
    GraphicsView *m_graphicsView;
};
}
#endif // BDSCHANNELONEVIEW_H
