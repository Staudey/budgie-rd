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

#include <QWidget>

#include "panel-manager-interface.h"
#include "shell-interface.h"

namespace Budgie::Panel
{
    /**
     * The basic lowlevel window part of the Panel implementation. Note this
     * is not the true Panel implementation, which must be subclassed from
     * the Window itself.
     */
    class Window : public QWidget
    {
        Q_OBJECT

    public:
        explicit Window(ShellInterface *interface);
        ~Window();

    private slots:
        void demoButtonClicked();
        void quitButtonClicked();

    private:
        WId m_winID;
        bool event(QEvent *event) override;
        void updateWindow();
        ShellInterface *m_shell;
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
