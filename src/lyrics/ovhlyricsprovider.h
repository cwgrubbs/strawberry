/*
 * Strawberry Music Player
 * Copyright 2019, Jonas Kvinge <jonas@jkvinge.net>
 *
 * Strawberry is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Strawberry is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Strawberry.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef OVHLYRICSPROVIDER_H
#define OVHLYRICSPROVIDER_H

#include "config.h"

#include <stdbool.h>

#include <QObject>
#include <QVariant>
#include <QString>

#include "lyricsprovider.h"
#include "jsonlyricsprovider.h"
#include "lyricsfetcher.h"

class QNetworkAccessManager;
class QNetworkReply;

class OVHLyricsProvider : public JsonLyricsProvider {
  Q_OBJECT

 public:
  explicit OVHLyricsProvider(QObject *parent = nullptr);

  bool StartSearch(const QString &artist, const QString &album, const QString &title, quint64 id);
  void CancelSearch(quint64 id);

 private slots:
  void HandleSearchReply(QNetworkReply *reply, const quint64 id, const QString &artist, const QString &title);

 private:
  static const char *kUrlSearch;
  QNetworkAccessManager *network_;
  void Error(const quint64 id, const QString &error, QVariant debug = QVariant());

};

#endif  // OVHLYRICSPROVIDER_H

