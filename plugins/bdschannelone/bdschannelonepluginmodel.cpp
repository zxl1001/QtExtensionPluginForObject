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
#include <QDebug>
#include <QUrl>

namespace BDSChannelOne {
BDSChannelOnePluginModel::BDSChannelOnePluginModel(QObject *parent)
    :PluginInterFace(parent),
      m_widget(Q_NULLPTR)
{
        m_widget = new BDSChannelOneView;
        connect(m_widget, SIGNAL(processData(ALGORITHM_TYPE,float)), this, SLOT(processMemiData(ALGORITHM_TYPE,float)));
}

BDSChannelOnePluginModel::~BDSChannelOnePluginModel()
{
    if(m_widget)
    {
        delete m_widget;
        m_widget = Q_NULLPTR;
    }
}

const QString &BDSChannelOnePluginModel::getPluginName() const
{
    return m_pluginName;
}

void BDSChannelOnePluginModel::setPluginName(const QString &pluginName)
{
    m_pluginName = pluginName;
}

QWidget *BDSChannelOnePluginModel::getWidget() const
{
    return m_widget;
}

const QMimeData &BDSChannelOnePluginModel::getMineData() const
{
    return m_mineData;
}

void BDSChannelOnePluginModel::setMimeData(const MIMEDATA_TYPE &mimetype, const QVariant &data)
{

    if(mimetype == MIMEDATA_TYPE::MIMEDATA_BYTEARRAY)
    {
        m_mineData.setData(MIMEDATA_BYTEARRAY_STRING, data.toByteArray());
    }
    else if(mimetype == MIMEDATA_TYPE::MIMEDATA_IMAGE)
    {
        m_mineData.setImageData(data);
    }
    else if(mimetype == MIMEDATA_TYPE::MIMEDATA_URL)
    {
        QList<QUrl> list;
        foreach (auto val, data.toList()) {
            list.append(QUrl(val.toUrl()));
        }
        m_mineData.setUrls(list);
    }
}

void BDSChannelOnePluginModel::processMemiData(ALGORITHM_TYPE type, float coefficient)
{
    qDebug()<<"BDSChannelOnePluginModel::processMemiData:"<<(int)type<<coefficient;
    QStringList list = QString(m_mineData.data(MIMEDATA_BYTEARRAY_STRING)).split(",");
    QVector<QPointF> points;
    for(int i=0; i<list.count(); ++i)
    {
        points.append(QPointF(qrand() % 500, list[i].toFloat()));
    }
    m_widget->setPoints(points);
    if(m_mineData.hasImage())
    {
        QImage image = qvariant_cast<QImage>(m_mineData.imageData());
        m_widget->setPixmap(QPixmap::fromImage(image));
    }


}

//namespace end
}
