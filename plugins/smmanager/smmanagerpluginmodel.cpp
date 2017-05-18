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

const QString &SMManagerPluginModel::getPluginName() const
{
    return m_pluginName;
}

QWidget *SMManagerPluginModel::getWidget() const
{
    return m_widget;
}

const QMimeData &SMManagerPluginModel::getMineData() const
{
    return m_mineData;
}

void SMManagerPluginModel::setMimeData(const MIMEDATA_TYPE &mimetype, const QVariant &data)
{
    if(mimetype == MIMEDATA_TYPE::MIMEDATA_BYTEARRAY)
    {
        m_mineData.setData(MIMEDATA_BYTEARRAY_STRING, data.toByteArray());
    }
}

void SMManagerPluginModel::setPluginName(const QString &pluginName)
{
    m_pluginName = pluginName;
}
//namespace end
}
