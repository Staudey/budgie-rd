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

#include <QObject>

#include "base-interface.h"

#define BudgieDisplayInterfaceIID "org.budgie-desktop.DisplayInterface"

namespace Budgie
{
    /**
     * The DisplayInterface abstracts away some of the core details of the
     * display management to encapsulate each Output as a Display
     */
    class DisplayInterface : public BaseInterface
    {
    public:
        virtual ~DisplayInterface()
        {
        }

        inline const QString interfaceName() override
        {
            return QStringLiteral(BudgieDisplayInterfaceIID);
        }

        /**
         * Return the index of this display in known set of displays
         */
        virtual uint index() = 0;

        /**
         * Return the geometry for display
         */
        virtual QRect geometry() = 0;
    };
}

Q_DECLARE_INTERFACE(Budgie::DisplayInterface, BudgieDisplayInterfaceIID)

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
