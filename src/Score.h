/*==LICENSE==
This file is part of Musec.
Copyright (C) 2013 Florian Meißner

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
==LICENSE==*/

#ifndef Score_h
#define Score_h

#include <QObject>

enum Difficulty {
    kHard = 1,
    kMedium,
    kEasy
};

class Score : public QObject {
    Q_OBJECT

public:
    Score();
    void addScore(bool title, bool artist, bool album);
    void updateMultiplier(int difficulty, quint32 songs);

    float average() { return fScore / fPlayed; }
    float multiplier() { return fMultiplier; }
    quint32 score() { return fScore; }
    quint32 played() { return fPlayed; }
    quint32 lastScore() { return fLastScore; }
    quint32 correctTitles() { return fCorrectTitles; }
    quint32 correctArtists() { return fCorrectArtists; }
    quint32 correctAlbums() { return fCorrectAlbums; }
    quint32 correctSets() { return fCorrectSets; }

private:
    float fMultiplier;
    quint32 fScore;
    quint32 fPlayed;
    quint32 fLastScore;
    quint32 fCorrectTitles;
    quint32 fCorrectArtists;
    quint32 fCorrectAlbums;
    quint32 fCorrectSets;

signals:
    void multiplierChanged(float value);
};
#endif