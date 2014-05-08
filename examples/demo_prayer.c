/************************************************************************
 *  Copyright (c) 2003, Arabeyes, Thamer Mahmoud
 *  Licensed under the LGPL license shown in file LICENSE
 *
 *  A full featured Muslim Prayer Times calculator
 *
 *  NOTE: This is a small example that uses the prayer.h. For more info on
 *  filling the structures and on supported methods read "prayer.h"
 *
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "../prayertime/prayer.h"


int main()
{

    int i, deg, min;
    double sec;
    const char symb =   (char)0xB0;
    char cityName[] ="Leiden";
    double qibla;

    Location loc;
    Method conf;
    Date date;

    Prayer ptList[6];
    Prayer imsaak;
    Prayer nextImsaak;
    Prayer nextFajr;

    /* fill the Date structure */
    date.day = 7;
    date.month = 5;
    date.year = 2014;
    /* fill the location info. structure */
    loc.degreeLat = 52.17138;
    loc.degreeLong = 4.48571;
    loc.gmtDiff = 1;
    loc.dst = 1;
    loc.seaLevel = 0;
    loc.pressure = 1010;
    loc.temperature= 10;


    /* auto fill the method structure. Have a look at prayer.h for a
     * list of supported methods */
    getMethod(5, &conf);
    conf.round = 0;

    /* Call the main function to fill the Prayer times array of
     * structures */
    getPrayerTimes (&loc, &conf, &date, ptList);

    /* Call functions for other prayer times and qibla */
    getImsaak (&loc, &conf, &date, &imsaak);
    getNextDayFajr (&loc, &conf, &date, &nextFajr);
    getNextDayImsaak (&loc, &conf, &date, &nextImsaak);
    qibla = getNorthQibla(&loc);


    /* Show the results */
    printf ("\nPrayer schedule for: %s on %2d/%2d/%4d\n", cityName,
            date.day, date.month, date.year);

    decimal2Dms (loc.degreeLat, &deg, &min, &sec);
    printf("\nLatitude\t=  %d%c %2d\' %4.1f\" %c", abs (deg), symb, abs (min),
           fabs (sec), (loc.degreeLat>=0) ? 'N' : 'S');

    decimal2Dms (loc.degreeLong, &deg, &min, &sec);
    printf ("\nLongitude\t=  %d%c %d\' %4.1f\" %c", abs (deg), symb, abs (min),
            fabs (sec), (loc.degreeLong>=0) ? 'E' : 'W');

    decimal2Dms (qibla, &deg, &min, &sec);
    printf("\nQibla\t\t=  %d%c %d\' %4.1f\" %c of true North\n", abs (deg), symb,
           abs (min), fabs (sec), (qibla>=0) ? 'W' : 'E');

    printf ("\n\n");

    for (i = 0; i < 6; i++)
        printf (" %3d:%02d:%02d%c", ptList[i].hour, ptList[i].minute, ptList[i].second,
                (ptList[i].isExtreme) ? '*' : ' ' );

    printf ("\n\n");
    printf("Tomorrow's Fajr:\t%3d:%02d\n", nextFajr.hour, nextFajr.minute);
    printf("Tomorrow's Imsaak:\t%3d:%02d\n", nextImsaak.hour, nextImsaak.minute);
    printf("Today's Imsaak:\t\t%3d:%02d\n\n", imsaak.hour, imsaak.minute);

    return 0;
}
