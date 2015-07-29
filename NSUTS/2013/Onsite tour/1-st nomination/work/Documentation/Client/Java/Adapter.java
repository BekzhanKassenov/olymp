import java.io.File;
import java.io.PrintStream;
import java.util.Map;

public class Adapter {
    private static SolutionInterface solution;

    static int worldAddr = -1;
    static int playerIndex = -1;

    private static PrintStream exceptionLog = null;

    private static void handleException(Throwable e) throws Throwable {
        PrintStream log = (exceptionLog == null) ? System.err : exceptionLog;
        e.printStackTrace(log);
        log.flush();
        throw e;
    }

    static void init(String classFile, int world, int player) throws Throwable {
        try {
            exceptionLog = new PrintStream(new File("JavaExceptions_" + player + ".txt"));

            worldAddr = world;
            playerIndex = player;

            if (SolutionInterface.playerIndex != player) {
                throw new AssertionError("SolutionInterface has been initialized too early");
            }
            if (WorldData.addr != world) {
                throw new AssertionError("WorldData has been initialized too early");
            }

            //TODO: set security manager
            String className = classFile.substring(0, classFile.length() - ".class".length());
            Class<?> solutionClass = Class.forName(className);
            solution = (SolutionInterface)solutionClass.newInstance();
        } catch (Throwable e) {
            handleException(e);
        }
    }

    static int[] strategy() throws Throwable {
        try {
            Map<Integer, Integer> res = solution.strategy();
            int[] arr = new int[res.size() * 2];
            int num = 0;
            for(Map.Entry<Integer, Integer> entry : res.entrySet()) {
                arr[num++] = entry.getKey();
                arr[num++] = entry.getValue();    
            }
            return arr;
        } catch (Throwable e) {
            handleException(e);
            return null;
        }
    }

    static String[] program(int robotIndex) throws Throwable {
        try {
            SolutionInterface.ProgramResult res = solution.program(robotIndex);
            return new String[] {res.stringData, res.scriptData};
        } catch (Throwable e) {
            handleException(e);
            return null;
        }
    }
}
