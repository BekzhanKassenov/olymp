/* DO NOT EDIT THIS FILE - it is machine generated */

import sun.misc.Unsafe;

public class Robot extends Unit {
    private static final int healthOffset = Unit.size;
    private static final int healthSize = intSize;

    public static int health (int addr) {
        return unsafe.getInt(addr + healthOffset);
    }

    private static final int shootTimeRemainingOffset = healthOffset + healthSize;
    private static final int shootTimeRemainingSize = intSize;

    public static int shootTimeRemaining (int addr) {
        return unsafe.getInt(addr + shootTimeRemainingOffset);
    }

    private static final int ammoRemainingOffset = shootTimeRemainingOffset + shootTimeRemainingSize;
    private static final int ammoRemainingSize = intSize;

    public static int ammoRemaining (int addr) {
        return unsafe.getInt(addr + ammoRemainingOffset);
    }


    static final int size = ammoRemainingOffset + ammoRemainingSize;
}

