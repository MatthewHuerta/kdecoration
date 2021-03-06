/*
 * Copyright 2014  Martin Gräßlin <mgraesslin@kde.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) version 3, or any
 * later version accepted by the membership of KDE e.V. (or its
 * successor approved by the membership of KDE e.V.), which shall
 * act as a proxy defined in Section 6 of version 3 of the license.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "mockbridge.h"
#include "mockclient.h"
#include "mocksettings.h"
#include <QtGlobal>

std::unique_ptr<KDecoration2::DecoratedClientPrivate> MockBridge::createClient(KDecoration2::DecoratedClient *client, KDecoration2::Decoration *decoration)
{
    auto ptr = std::unique_ptr<MockClient>(new MockClient(client, decoration));
    m_lastCreatedClient = ptr.get();
    return std::move(ptr);
}

std::unique_ptr<KDecoration2::DecorationSettingsPrivate> MockBridge::settings(KDecoration2::DecorationSettings *parent)
{
    auto ptr = std::unique_ptr<MockSettings>(new MockSettings(parent));
    m_lastCreatedSettings = ptr.get();
    return std::move(ptr);
}

void MockBridge::update(KDecoration2::Decoration *decoration, const QRect &geometry)
{
    Q_UNUSED(decoration)
    Q_UNUSED(geometry)
}
