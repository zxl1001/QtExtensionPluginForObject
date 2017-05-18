/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    MainWindow.cpp
 * @brief
 *******************************************************************************
 */
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "plugindialog.h"
#include "plugininterface/plugininterface.h"

static const char PLUGIN_PATH[] = "/plugins";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_setting(Q_NULLPTR)
{
    ui->setupUi(this);
    QVector<QWidget *> vector;
    for(int i=0; i<ui->stackedWidget->count(); ++i)
    {
        vector.append(ui->stackedWidget->widget(i));
    }
    for(int i=0; i< vector.size(); ++i)
    {
        ui->stackedWidget->removeWidget(vector[i]);
    }

    m_setting = new QSettings("ZXL1001");
    QStringList plugingPath;
    plugingPath.append(qApp->applicationDirPath() + QLatin1String(PLUGIN_PATH));
    connect(ExtensionSystem::PluginManager::instance(), SIGNAL(objectAdded(QObject*)), this, SLOT(pluginObjectAdded(QObject*)));
    ExtensionSystem::PluginManager::setFileExtension(QLatin1String("pluginspec"));
    ExtensionSystem::PluginManager::setGlobalSettings(m_setting);
    ExtensionSystem::PluginManager::setPluginPaths(plugingPath);

//    const ExtensionSystem::PluginSpecSet plugins = ExtensionSystem::PluginManager::plugins();
//    foreach (ExtensionSystem::PluginSpec *spec, plugins) {
//        qDebug()<<spec->name()<<spec->hasError()<<spec->state();
//        ui->listWidget->addItem(spec->name());

//    }
    ExtensionSystem::PluginManager::loadPlugins();

    if(ExtensionSystem::PluginManager::hasError())
    {
        ExtensionSystem::PluginErrorOverview errorOverview;
        errorOverview.exec();
        qApp->quit();
    }
    connect(this, SIGNAL(aboutToQuit()), &plgManager, SLOT(shutdown()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pluginObjectAdded(QObject *obj)
{
    qDebug()<<"plugin be add."<<obj;
    PluginInterFace *item = dynamic_cast<PluginInterFace*>(obj);
    if(item != Q_NULLPTR)
    {
        QString pluginName = item->getPluginName();
        ui->listWidget->addItem(pluginName);
        if(pluginName == "BDSChannelOnePlugin")
        {
            item->setMimeData(MIMEDATA_TYPE::MIMEDATA_BYTEARRAY, "50,80,190,7,26,353,602,884,25,198,499");
            item->setMimeData(MIMEDATA_TYPE::MIMEDATA_IMAGE, QImage("/home/zxl/Pictures/Screenshot from 2017-04-24 17:42:48.png"));
        }
        QWidget * widget = item->getWidget();
        if(widget != Q_NULLPTR)
        {
            ui->stackedWidget->addWidget(widget);
        }
    }
}


void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    ui->stackedWidget->setCurrentIndex(index.row());
}

void MainWindow::on_pluginViewBtn_clicked()
{
    qDebug()<<"aaaa";
    PluginDialog d(Q_NULLPTR);
    d.exec();
}
