/*double r1 = 0;
    if (_y1 + _y2 < (l - _y1) + (l - _y2)) {
        r1 = ternary(_x1, _y1, _x2, _y2, 0, min(_y1, _y2), 0, max(_y1, _y2));
    } else {
        r1 = ternary(_x1, _y1, _x2, _y2, w, min(_y1, _y2), w, max(_y1, _y2));
    }

    double r2 = 0;
    if (_x1 + _x2 < (w - _x1) + (w - _x2)) {
        r2 = ternary(_x1, _y1, _x2, _y2, min(_x1, _x2), 0, max(_x1, _x2), 0);
    } else {
        r2 = ternary(_x1, _y1, _x2, _y2, min(_x1, _x2), l, max(_x1, _x2), l);
    }

    return min(r1, r2);
    */

    
    double r1 = ternary(_x1, _y1, _x2, _y2, 0, min(_y1, _y2), 0, max(_y1, _y2));
    double r2 = ternary(_x1, _y1, _x2, _y2, w, min(_y1, _y2), w, max(_y1, _y2));
    double r3 = ternary(_x1, _y1, _x2, _y2, min(_x1, _x2), 0, max(_x1, _x2), 0);
    double r4 = ternary(_x1, _y1, _x2, _y2, min(_x1, _x2), l, max(_x1, _x2), l);

    /*
    double r1 = dist(_x1, _y1, 0, (_y1 + _y2) / 2.0) + dist(_x2, _y2, 0, (_y1 + _y2) / 2.0); // left
    double r2 = dist(_x1, _y1, w, (_y1 + _y2) / 2.0) + dist(_x2, _y2, w, (_y1 + _y2) / 2.0); // right
    double r3 = dist(_x1, _y1, (_x1 + _x2) / 2.0, 0) + dist(_x2, _y2, (_x1 + _x2) / 2.0, 0); // down
    double r4 = dist(_x1, _y1, (_x1 + _x2) / 2.0, l) + dist(_x2, _y2, (_x1 + _x2) / 2.0, l); // up
    */
    
    return min(min(r1, r2), min(r3, r4));
