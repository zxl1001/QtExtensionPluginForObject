/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    smmanagerpluginmodel.cpp
 * @brief
 *******************************************************************************
 */
#include "smmanagerpluginmodel.h"
namespace SMManager{
SMManagerPluginModel::SMManagerPluginModel(QObject *parent)
    :PluginInterFace(parent),
      m_widget(Q_NULLPTR)
{
    m_widget = new SMManagerView;
}

SMManagerPluginModel::~SMManagerPluginModel()
{
    if(m_widget != Q_NULLPTR)
    {
        delete m_widget;
        m_widget = Q_NULLPTR;
    }
}

QString SMManagerPluginModel::getPluginName()
{
    return "zxlSMManagerPluginModel";
}

QWidget *SMManagerPluginModel::getWidget()
{
    return m_widget;
}
//namespace end
}
