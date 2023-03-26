#include "GraphicsView.h"

QString sample() {
    return QString("total 52\n"
                   " rw-rw-r-- 1 bilac bilac  1830 Mar 25 22:06 CMakeLists.txt\n"
                   "-rw-rw-r-- 1 bilac bilac 27151 Mar 25 08:17 CMakeLists.txt.user\n"
                   "-rw-rw-r-- 1 bilac bilac   472 Mar 25 22:38 GraphicsView.cpp\n"
                   "-rw-rw-r-- 1 bilac bilac   359 Mar 25 22:38 GraphicsView.h\n"
                   "-rw-rw-r-- 1 bilac bilac   202 Mar 25 08:18 main.cpp\n"
                   "-rw-rw-r-- 1 bilac bilac  2131 Mar 25 22:40 MainWindow.cpp\n"
                   "-rw-rw-r-- 1 bilac bilac   649 Mar 25 22:24 MainWindow.h");
};

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
    painter->drawText(rect, sample());
}

QRectF GraphicsView::visibleArea() const {
    QPointF top = mapToScene (0, 0);
    QPointF bottom = mapToScene (width(), height());
    return QRectF (top, bottom);
}
