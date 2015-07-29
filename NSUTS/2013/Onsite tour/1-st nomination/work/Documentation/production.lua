function sqr(x)
    return x*x
end
function Distance(x1, y1, x2, y2)
    return math.sqrt(sqr(x1-x2) + sqr(y1-y2))
end

pathIndex = nil
goX = nil;
goY = nil;
victimId = nil;
dx = 0; dy = 0;
oldx = nil; oldy = nil;
stay = 0;

function seeClosest()
	local mX, mY = api:position(0) --Наши координаты
    local n = api:count() --количество юнитов в радиусе видимости
    local myOwner = api:owner(0)--наш номер игрока (владелец робота)

    local closestEnemy = 1.5 * api.field_size
    for i = 1, n do
        if (api:type(i) == 2) then -- Юнит - робот
            local town = api:owner(i); -- Кому принадлежит робот
            if (town ~= myOwner and town >= 0) then -- Если вражеский робот
                local sx, sy = api:position(i) -- Позиция вражеского робота
                local dist = Distance(sx, sy, mX, mY) -- Расстояние до него
                if (dist < closestEnemy) then -- Проверка на кратчайшее расстояние
                    shotX, shotY = sx, sy -- Сохранение результата, если робот находится ближе чем предыдущий найденный
                    closestEnemy = dist;     
                end
            end
        end
    end
    return shotX, shotY;


end

tact = 0
X1 = nil
Y1 = nil

function ShootAt() 
	if (X1 == nil) then
		X1, Y1 = seeClosest();
		if X1 == nil then
			api:shoot_stop()
		end
	end
	tact = tact + 1
	local X2, Y2
	if (tact >= 4) then
		X2, Y2  = seeClosest();
		if X2 == nil then
	    	--api:shoot_stop();     
			return
		end
		--MoveToRandomPoint();
		tact = 0
		local X3 = X2 + (X2 - X1)*1.1 
		local Y3 = Y2 + (Y2 - Y1)*1.1
		api:shoot_at_pos(X3, Y3);
		X1 = nil
		Y1 = nil
		

	end

end 

--Стрелять в ближайшего врага
function ShootAtClosest()
    local mX, mY = api:position(0) --Наши координаты
    local n = api:count() --количество юнитов в радиусе видимости
    local myOwner = api:owner(0)--наш номер игрока (владелец робота)

    local closestEnemy = 1.5 * api.field_size
    local shotX = nil
    local shotY = nil
    for i = 1, n do
        if (api:type(i) == 2) then -- Юнит - робот
            local town = api:owner(i); -- Кому принадлежит робот
            if (town ~= myOwner and town >= 0) then -- Если вражеский робот
                local sx, sy = api:position(i) -- Позиция вражеского робота
                local dist = Distance(sx, sy, mX, mY) -- Расстояние до него
                if (dist < closestEnemy) then -- Проверка на кратчайшее расстояние
                    shotX, shotY = sx, sy -- Сохранение результата, если робот находится ближе чем предыдущий найденный
                    closestEnemy = dist;
                end
            end
        end
    end
    if (shotX) then -- если нашли хоть одного в области видимости
        api:shoot_at_pos(shotX, shotY)
    else
        api:shoot_stop()
    end
end

function MoveToPoint(x, y) -- Двигаемся в точку x,y
    local mX, mY = api:position(0)
    if (x == 0) and (y == 0) then
		MoveToRandomPoint();
	end
    api:move_by_delta(x - mX + dx, y - mY + dy )
end

function MoveAlongPath(path, isCycle) -- Двигаемся вдоль контура path, если isCycle = true, то зацикливаемся по контуру
    if (path == nil) then
        return
    end
    if (pathIndex == nil) then
        pathIndex = 0
    end
        local mX, mY = api:position(0)
        if (Distance(mX, mY, path[pathIndex].x, path[pathIndex].y) < 1e-5) then
          pathIndex = pathIndex + 1
        end
    if (path[pathIndex] == nil) then
        if (not isCycle) then
            return
        end
        pathIndex = 0
    end
    MoveToPoint(path[pathIndex].x, path[pathIndex].y)
end

function MoveToRandomPoint() 
	if goX == nil then
		goX = math.random();
		goY = math.random();
		goX = goX * api.field_size;
		goY = goY * api.field_size;
	end
	MoveToPoint(goX, goY);
end

function MoveToTempRandomPoint() 
	local goX = math.random();
	local goY = math.random();
	goX = goX * api.field_size;
	goY = goY * api.field_size;
	MoveToPoint(goX, goY);
end

function FindVictim() 
	local myOwner = api:owner(0)
	if victimId == nil then
		local n = api:count();
		if n == 0 then
			MoveToRandomPoint();
		else
			moved = false;
			for i = 1, n do
				if (api:type(i) == 2) and (api:owner(i) ~= myOwner) then
					victimId = i;
					MoveToPoint(api:position(i));
					--moved = true;
					break;
				end 
			end
			if moved == false then
				MoveToRandomPoint()
			end
		end
	else
		MoveToPoint(api:position(victimId));
	end
end

function Drag() 
	MoveToRandomPoint();
end

function evade() 
	
end

rx = nil
ry = nil

function Think()
	if rx == nil then rx = math.random()*20 - 20 ry = math.random()*20 - 20 end
	
	local x, y = api:position(0);
	if (gofact ~= nil) and (x == gofact.x) and (y == gofact.y) then
		stay = 0;
	elseif (oldx ~= nil) and (oldx == x) and (oldy == y) then
		stay = stay + 1;
		if stay == 10 then
			goX = nil;
		end
		if stay > 5 then
			Drag();
			stay = stay + 1;
			if stay > 25 then
				stay = 0;
			end
			return;
		end
	else
		stay = 0;
	end
	

	oldx, oldy = api:position(0);
	
	if (path) then
		MoveAlongPath(path, true);
	elseif (isKiller) then -- Действуем в зависимости от типа робота, определенного в функции Program (ProgramRobot для fpc). Либо робот движущийся по контуру, либо робот движущийся в определенную фабрику
        FindVictim();
    else
       --MoveToPoint(gofact.x, gofact.y);
       MoveToPoint(gofact.x + rx, gofact.y + ry);
    end
      
    ShootAt();
    --ShootAtClosest() -- Стреляем в ближайшего соперника
end
