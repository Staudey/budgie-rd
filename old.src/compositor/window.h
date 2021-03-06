/*
 * This file is part of budgie-rd
 *
 * Copyright © 2017-2018 Budgie Desktop Developers
 *
 * budgie-rd is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */

#pragma once

#include <QScopedPointer>
#include <QWaylandCompositor>
#include <QWaylandOutput>
#include <QWindow>

/* OpenGL */
#include <QOpenGLPaintDevice>
#include <QOpenGLTextureBlitter>
#include <QOpenGLWindow>

#include "compositor-common.h"
#include "surface-item.h"

namespace Budgie
{
    /**
     * The CompositorWindow wraps a QWaylandOutput to provide actual output
     * on screen, and is responsible for rendering.
     */
    class CompositorWindow : public QOpenGLWindow
    {
        Q_OBJECT

        friend class Compositor;

    public:
        explicit CompositorWindow(Compositor *compositor, QWaylandOutput *output);

        /**
         * Get the QWaylandOutput we're associated with
         */
        QWaylandOutput *output();

        /**
         * Get the QWaylandCompositor we're associated with
         */
        QWaylandCompositor *compositor();

        CompositorView *mapSurface(CompositorSurfaceItem *surface);
        void unmapSurface(CompositorSurfaceItem *surface);

    protected:
        Compositor *m_compositor;
        QScopedPointer<QWaylandOutput> m_output;

        void scheduleDraw();

    private slots:
        void currentModeChanged();

    private:
        /* OpenGL stuff */
        QOpenGLTextureBlitter m_GLBlitter;
        QOpenGLPaintDevice *m_GLDevice;

        void initializeGL() override;
        void paintGL() override;
        void doRender();
        void renderSurface(CompositorSurfaceItem *surface);

        /* Map each surface to our own private view here */
        QHash<CompositorSurfaceItem *, QSharedPointer<CompositorView>> m_views;
    };
}
/*
 * Editor modelines  -  https://www.wireshark.org/tools/modelines.html
 *
 * Local variables:
 * c-basic-offset: 4
 * tab-width: 4
 * indent-tabs-mode: nil
 * End:
 *
 * vi: set shiftwidth=4 tabstop=4 expandtab:
 * :indentSize=4:tabSize=4:noTabs=true:
 */
