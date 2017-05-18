/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    graphicsview.cpp
 * @brief
 *******************************************************************************
 */
#include "graphicsview.h"

GraphicsView::GraphicsView(QWidget *parent)
    :QGraphicsView(parent),
      m_scene(new GraphicsScene(this)),
      m_pathItem(new QGraphicsPathItem),
      m_pixmapItem(new QGraphicsPixmapItem)
{
    setAlignment(Qt::AlignTop | Qt::AlignLeft);
    setBackgroundBrush(Qt::black);

    m_pixmapItem->setFlag(QGraphicsItem::ItemIsMovable, true);
    m_pathItem->setFlag(QGraphicsItem::ItemIsMovable, true);
    m_pathItem->setBrush(Qt::NoBrush);
    m_pathItem->setPen(QPen(Qt::green, 5));
    m_scene->setSceneRect(0,0,1024,768);
    m_scene->addItem(m_pixmapItem);
    m_scene->addItem(m_pathItem);
    setScene(m_scene);
}

GraphicsView::~GraphicsView()
{
    if(m_pathItem)
    {
        delete m_pathItem;
        m_pathItem = Q_NULLPTR;
    }
    if(m_pixmapItem)
    {
        delete m_pixmapItem;
        m_pixmapItem = Q_NULLPTR;
    }
}

void GraphicsView::setPoints(const QVector<QPointF> &points)
{
    m_points = points;
    QPainterPath path;
    path.moveTo(m_points.first());
    for(int i=0; i<m_points.count(); ++i)
    {
        path.lineTo(m_points[i]);
    }
    m_pathItem->setPath(path);

    update();
}

void GraphicsView::setPixmap(const QPixmap &pic)
{
    m_pixmapItem->setPixmap(pic);
    update();
}

GraphicsScene::GraphicsScene(QObject *parent)
    :QGraphicsScene(parent)
{

}
