/* DO NOT EDIT THIS FILE - it is machine generated */

import sun.misc.Unsafe;

public class ProjectileClass extends Constants {
    private static final int damageOffset = 0;
    private static final int damageSize = intSize;

    public static int damage (int addr) {
        return unsafe.getInt(addr + damageOffset);
    }

    private static final int isHomingOffset = damageOffset + damageSize;
    private static final int isHomingSize = intSize;

    public static int isHoming (int addr) {
        return unsafe.getInt(addr + isHomingOffset);
    }

    private static final int speedOffset = isHomingOffset + isHomingSize;
    private static final int speedSize = doubleSize;

    public static double speed (int addr) {
        return unsafe.getDouble(addr + speedOffset);
    }

    private static final int maxLifeTimeOffset = speedOffset + speedSize;
    private static final int maxLifeTimeSize = doubleSize;

    public static double maxLifeTime (int addr) {
        return unsafe.getDouble(addr + maxLifeTimeOffset);
    }


    static final int size = maxLifeTimeOffset + maxLifeTimeSize;
}
