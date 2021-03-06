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

#include "base-interface.h"
#include "panel-manager-interface.h"
#include "raven-interface.h"

#define BudgieShellInterfaceIID "org.budgie-desktop.ShellInterface"

namespace Budgie
{
    /**
     * The ShellInterface provides access to the Shell APIs, and allows
     * registration and querying of services.
     */
    class ShellInterface : public BaseInterface
    {
    public:
        virtual ~ShellInterface()
        {
        }

        inline const QString interfaceName() override
        {
            return QStringLiteral(BudgieShellInterfaceIID);
        }

        /**
         * Temporary interface, handles the main shutdown routine of the
         * Shell. In future this will be hidden behind session controls
         */
        virtual void shutdown() = 0;

        /**
         * Return the session name
         */
        virtual const QString &sessionName() = 0;

        /**
         * Register some interface with the ShellInterface so that it
         * can be accessed later.
         */
        virtual bool registerInterface(BaseInterface *instance, const QString &id = nullptr) = 0;

        /**
         * Attempt to retrieve an implementation of the given interface
         * from the ShellInterface context, if one exists.
         */
        virtual BaseInterface *getInterface(const QString &id) = 0;

        /**
         * Ask the implementation if it has the given interface or not
         */
        virtual bool hasInterface(const QString &id) = 0;

        /* Friendly accessors for well known interfaces */

        /**
         * Return the registered Panel Manager, if one is present in this desktop
         */
        virtual PanelManagerInterface *getPanelManager() = 0;

        /**
         * Get the registered Raven instance, if one is present in this desktop
         */
        virtual RavenInterface *getRaven() = 0;
    };
}

Q_DECLARE_INTERFACE(Budgie::ShellInterface, BudgieShellInterfaceIID)

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
