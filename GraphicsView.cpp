#include "GraphicsView.h"
#include "Logger.h"

GraphicsView::GraphicsView(QGraphicsScene *scene)
    : QGraphicsView(scene),
      m_font("Monospace", 2),
      m_color(Qt::white) {
    setBackgroundBrush(QColor(48, 48, 48));
}

void GraphicsView::zoomAll() {
    fitInView(sceneRect(), Qt::KeepAspectRatio);
}

void GraphicsView::resizeEvent(QResizeEvent *event) {
    zoomAll();
}

void GraphicsView::drawForeground(QPainter *painter, const QRectF &rect) {
    painter->setPen(m_color);
    painter->setFont(m_font);
    painter->drawText(rect, logger().messages());
}

QRectF GraphicsView::visibleArea() const {
    QPointF top = mapToScene (0, 0);
    QPointF bottom = mapToScene (width(), height());
    return QRectF (top, bottom);
}
