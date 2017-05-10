/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    BDSChannelOnePluginModel.cpp
 * @brief
 *******************************************************************************
 */
#include "bdschannelonepluginmodel.h"
namespace BDSChannelOne {
BDSChannelOnePluginModel::BDSChannelOnePluginModel(QObject *parent)
    :PluginInterFace(parent),
      m_widget(Q_NULLPTR)
{
        m_widget = new BDSChannelOneView;
}

BDSChannelOnePluginModel::~BDSChannelOnePluginModel()
{
    if(m_widget)
    {
        delete m_widget;
        m_widget = Q_NULLPTR;
    }
}

QString BDSChannelOnePluginModel::getPluginName()
{
    return "zxlBDSChannelOnePluginModel";
}

QWidget *BDSChannelOnePluginModel::getWidget()
{
    return m_widget;
}

//namespace end
}
