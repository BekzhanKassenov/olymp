/* DO NOT EDIT THIS FILE - it is machine generated */

import sun.misc.Unsafe;

public class Factory extends Unit {
    private static final int robotClassIdxOffset = Unit.size;
    private static final int robotClassIdxSize = intSize;

    public static int robotClassIdx (int addr) {
        return unsafe.getInt(addr + robotClassIdxOffset);
    }

    private static final int buildTimeRemainingOffset = robotClassIdxOffset + robotClassIdxSize;
    private static final int buildTimeRemainingSize = intSize;

    public static int buildTimeRemaining (int addr) {
        return unsafe.getInt(addr + buildTimeRemainingOffset);
    }

    private static final int capturingPlayerOffset = buildTimeRemainingOffset + buildTimeRemainingSize;
    private static final int capturingPlayerSize = intSize;

    public static int capturingPlayer (int addr) {
        return unsafe.getInt(addr + capturingPlayerOffset);
    }

    private static final int captureProgressTimeOffset = capturingPlayerOffset + capturingPlayerSize;
    private static final int captureProgressTimeSize = intSize;

    public static int captureProgressTime (int addr) {
        return unsafe.getInt(addr + captureProgressTimeOffset);
    }


    static final int size = captureProgressTimeOffset + captureProgressTimeSize;
}

