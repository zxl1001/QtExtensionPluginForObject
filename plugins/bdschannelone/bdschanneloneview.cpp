/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    smmanagerview.cpp
 * @brief
 *******************************************************************************
 */
#include "bdschanneloneview.h"
#include "ui_bdschanneloneview.h"
#include <QDebug>

namespace BDSChannelOne {
BDSChannelOneView::BDSChannelOneView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDSChannelOneView),
    m_graphicsView(new GraphicsView(this))
{
    ui->setupUi(this);
    ui->frame->layout()->addWidget(m_graphicsView);
}

BDSChannelOneView::~BDSChannelOneView()
{
    delete ui;
}

void BDSChannelOneView::setPoints(const QVector<QPointF> &points)
{
    m_graphicsView->setPoints(points);
}

void BDSChannelOneView::setPixmap(const QPixmap &image)
{
    m_graphicsView->setPixmap(image);
}

void BDSChannelOneView::on_processBtn_clicked()
{
    emit processData((ALGORITHM_TYPE)(ui->comboBox->currentIndex()), ui->doubleSpinBox->value());
}

//namespace end
}



