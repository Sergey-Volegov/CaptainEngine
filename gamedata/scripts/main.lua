require "class_maker"
require "player"

function Core:onSetup()
	-- Settings --
	Core.setProperty("window_size", Point(1280, 720))
	Core.setProperty("fps", 60)

	-- Resources loading --
	Core.loadTilesetsForLevel("test", "TILED_MANAGER")
	Core.current_level = Core.loadLevel("test", "TILED_MANAGER")

	local cont = Core.current_level:getContainer("objects");
	print(ObjectLayer.fromContainer(cont):getFirstObject():getName())
end

function Core:onClose()
	
end

function Core:onUpdate()
	
end