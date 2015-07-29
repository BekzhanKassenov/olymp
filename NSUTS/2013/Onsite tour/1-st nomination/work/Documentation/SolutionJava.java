import java.util.Map;
import java.util.ArrayList;
import java.lang.Math;

public class SolutionJava implements SolutionInterface {
    public Map<Integer, Integer> strategy() {
        Map<Integer,Integer> res = new java.util.HashMap<Integer,Integer>();
        for (int i = 0; i < Constants.MAX_FACTORY_COUNT; i++) {
            int fact = WorldData.factory(i);
            if (Unit.id(fact) < 0) continue; //пропускаем "мёртвые" заводы
            if (Unit.owner(fact) == playerIndex) //если завод наш
                res.put(Unit.id(fact), 0); //то говорим строить на нём роботов
        }
        return res;
    } 
    public ProgramResult program(int idx) {
        if (idx%2 == 1) {
            double rat = 0.01;
            //пишем в строку инициализирующий скрипт на LUA (задаём путь для патруля)
            String script = String.format("path = {}\npath[0] = {x = %f, y = %f}\npath[1] = {x = %f, y = %f}\npath[2] = {x = %f, y = %f}\npath[3] = {x = %f, y = %f}\n",
                Constants.FIELD_SIZE*rat, Constants.FIELD_SIZE*rat,
                Constants.FIELD_SIZE*(1-rat), Constants.FIELD_SIZE*rat,
                Constants.FIELD_SIZE*(1-rat), Constants.FIELD_SIZE*(1-rat), 
                Constants.FIELD_SIZE*rat, Constants.FIELD_SIZE*(1-rat));
            return new ProgramResult(new String(), script);
        } else {
            //выбираем произвольный завод
            int num = idx%7;
            int f = WorldData.factory(num);
            //пишем инициализирующий скрипт: бежать в центр этого завода
            String script = String.format("gofact = {x = %f, y = %f}", CoordsXY.x(Unit.position(f)), CoordsXY.y(Unit.position(f)));
            return new ProgramResult(new String(), script);
        }
    } 
}
