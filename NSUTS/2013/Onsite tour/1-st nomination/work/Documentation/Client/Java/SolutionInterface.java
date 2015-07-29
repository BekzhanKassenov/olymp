import java.util.Map;

public interface SolutionInterface {
    
    public static final int playerIndex = Adapter.playerIndex;

    public Map<Integer, Integer> strategy();

    public ProgramResult program(int robotIndex);

    public static class ProgramResult {
        String stringData;
        String scriptData;

        public ProgramResult(String stringData, String scriptData) {
            this.stringData = stringData;
            this.scriptData = scriptData;
        }
    }
}
