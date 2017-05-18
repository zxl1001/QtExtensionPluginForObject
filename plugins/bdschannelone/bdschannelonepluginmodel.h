/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    BDSChannelOnePluginModel.h
 * @brief
 *******************************************************************************
 */
#ifndef BDSCHANNELONEPLUGINMODEL_H
#define BDSCHANNELONEPLUGINMODEL_H

#include "plugininterface/plugininterface.h"
#include "bdschanneloneview.h"
namespace BDSChannelOne {
class BDSChannelOnePluginModel : public PluginInterFace
{
    Q_OBJECT
public:
    explicit BDSChannelOnePluginModel(QObject *parent=0);
    virtual ~BDSChannelOnePluginModel();

    virtual const QString &getPluginName() const;
    virtual void setPluginName(const QString &pluginName);
    virtual QWidget * getWidget() const;
    virtual const QMimeData &getMineData() const;
    virtual void setMimeData(const MIMEDATA_TYPE &mimetype, const QVariant &data);

public Q_SLOTS:
    void processMemiData(ALGORITHM_TYPE, float coefficient);
private:
    BDSChannelOneView *m_widget;
};
}
#endif // BDSCHANNELONEPLUGINMODEL_H
