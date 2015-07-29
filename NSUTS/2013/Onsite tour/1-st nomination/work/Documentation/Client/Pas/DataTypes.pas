unit DataTypes;
{$A1}
interface 

Type CoordsXY = Object
    x : double;
    y : double;
end;

Type WorldUnit = Object
    id : longint;
    owner : integer;
    unitType  : integer;
    position : CoordsXY;
    radius : double;
    classIdx : longint;
end;

Type Factory = Object(WorldUnit)
    robotClassIdx : longint;
	buildTimeRemaining : longint;
	capturingPlayer : longint;
	captureProgressTime : longint;
End;

Type Robot = Object(WorldUnit)
    health : longint;
	shootTimeRemaining : longint;
	ammoRemaining : longint;
end;

Type Projectile = Object(WorldUnit)
	velocity : CoordsXY;
	homingTargetId : longint;
	lifeTimeRemaining : double;
end;

Type FactoryClass = Object
	radius : double;
	timeToCapture : longint;
    maxCapturingRobots : longint;
	score : longint;
end;

Type RobotClass = Object
	radius : double;
	visibilityRadius : double;
	maxHealth : longint;
	maxSpeed : double;
	projectileClassIdx : longint;
	shootTimeCooldown : longint;
	totalAmmo : longint;
	timeToBuild : longint;
	score : longint;
end;

Type ProjectileClass = Object
	damage : longint;
	isHoming : longint;
	speed : double;
	maxLifeTime : double;
end;

const PLAYERS_COUNT = 2;
const FIELD_SIZE = 1000.0;

const FACTORY_CLASS_COUNT = 1;
const ROBOT_CLASS_COUNT = 1;
const PROJECTILE_CLASS_COUNT = 1;

const MAX_FACTORY_COUNT = 10;
const MAX_ROBOT_COUNT = 1024;
const MAX_PROJECTILE_COUNT = 5120;


Type WorldData = Record
	currentTime : longint;
	maximalMatchTime : longint;
	factoryClasses : array[0..FACTORY_CLASS_COUNT-1] of FactoryClass;
	robotClasses : array[0..ROBOT_CLASS_COUNT-1] of RobotClass;
	projectileClasses : array[0..PROJECTILE_CLASS_COUNT-1] of ProjectileClass;
	factories : array[0..MAX_FACTORY_COUNT-1] of Factory;
	robots : array[0..MAX_ROBOT_COUNT-1] of Robot;
	projectiles : array[0..MAX_PROJECTILE_COUNT-1] of Projectile;
End;


const MAX_UNITS_COUNT = MAX_FACTORY_COUNT + MAX_ROBOT_COUNT + MAX_PROJECTILE_COUNT;
const WORLD_DATA_SIZE = sizeof(WorldData);



Type ptrWorldData   = ^WorldData;

procedure SetBuildAt(id, classIdx : longint);

var world : ptrWorldData;
    playerIndex : longint;
    robotTypesArray : plongint;



implementation
    procedure SetBuildAt(id, classIdx : longint);
    begin
    	if ((id < 0) or (id >= MAX_FACTORY_COUNT)) then
            writeln('Id is out of range :', id)
    	else
            robotTypesArray[id] := classIdx;
    end;
end.
