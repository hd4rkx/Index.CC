loadstring([[
    function LPH_NO_VIRTUALIZE(f) return f end;
]])(); 
if (not LPH_OBFUSCATED) then
    LPH_NO_VIRTUALIZE = function(...) return (...) end;
    LPH_JIT_MAX = function(...) return (...) end;
    LPH_JIT_ULTRA = function(...) return (...) end;
end

getgenv().KingVon = {
    ["Aimbot"] = {
        ["Enabled"] = false,
        ["Future"] = 0.1,
        ["Keybind"] = Enum.KeyCode.C,
        ["Target"] = "UpperTorso",
        ["ShakeValue"] = 0,
    },
    ["CamOrientation"] = {
        ["Enabled"] = false,
        ["GroundPrediction"] = 0.1,
        ["AirPrediction"] = 0.1,
        ["GroundSmoothness"] = 0.1,
        ["AirSmoothness"] = 0.1,
        ["EasingStyle"] = Enum.EasingStyle.Linear,
    },
    ["Visuals"] = {
        ["Box"] = {
            ["Enabled"] = false,
            ["Size"] = Vector3.new(10, 10, 10),
            ["Transparency"] = 0.8,
            ["Color"] = Color3.fromRGB(255, 255, 255),
        },
        ["Circle"] = {
            ["Enabled"] = false,
            ["Radius"] = 5,
            ["Color"] = Color3.fromRGB(255, 255, 255),
            ["Thickness"] = 1,
        },
        ["Tracer"] = {
            ["Enabled"] = false,
            ["Color"] = Color3.fromRGB(255, 255, 255),
            ["Thickness"] = 1,
            ["StartPosition"] = "Mouse", 
        },
    },
    ["Strafer"] = {
        ["Enable"] = false,
        ["X"] = 5, 
        ["Y"] = 0, 
        ["Z"] = 10, 
    },
    ["Random"] = {
        ["AutoAir"] = false,
        ["AutoAirDelay"] = 0.13,
    }
}

task.wait(2)

local aaaa = {
    BoxOutlineColor = Color3.new(0, 0, 0),
    BoxColor = Color3.new(1, 1, 1),
    NameColor = Color3.new(1, 1, 1),
    HealthOutlineColor = Color3.new(0, 0, 0),
    HealthHighColor = Color3.new(0, 1, 0.164706),
    HealthLowColor = Color3.new(1, 0, 0),
    Teamcheck = false,
    Enabled = false,
    ShowBox = false,
    ShowName = false,
    ShowHealth = false,
    ShowDistance = false,
}
Script = {
    Table = getgenv().KingVon,
    Target = nil,
    MainEvent = nil,
    Argument = "",
    Functions = {},
    Connections = {},
    Tool = nil
}
Script.Table = getgenv().KingVon
local function PlayThatBitch()
        local playerGui = game.Players.LocalPlayer:WaitForChild("PlayerGui")

        local screenGui = Instance.new("ScreenGui")
        screenGui.Name = "IntroScreen"
        screenGui.Parent = playerGui

        local frame = Instance.new("Frame")
        frame.Name = "IntroFrame"
        frame.Parent = screenGui
        frame.Size = UDim2.new(1, 0, 1, 0)
        frame.BackgroundTransparency = 1

        local imageLabel = Instance.new("ImageLabel")
        imageLabel.Name = "IntroImage"
        imageLabel.Parent = frame
        imageLabel.Size = UDim2.new(0.01, 0, 0.01, 0)  
        imageLabel.Position = UDim2.new(0.5, -0.1, 0.5, -0.1) 
        imageLabel.Image = "rbxassetid://106428636831184"
        imageLabel.BackgroundTransparency = 1
        imageLabel.ImageTransparency = 100
        imageLabel.AnchorPoint = Vector2.new(0.5, 0.5)

        local sound = Instance.new("Sound")
        sound.Name = "IntroSound"
        sound.Parent = frame
        sound.SoundId = "rbxassetid://6580172940"
        sound.Volume = 50
        sound:Play()

        local tweenService = game:GetService("TweenService")

        local blurEffect = Instance.new("BlurEffect")
        blurEffect.Parent = game.Lighting
        blurEffect.Size = 60

        local zoomTweenInfo = TweenInfo.new(0.4, Enum.EasingStyle.Quad, Enum.EasingDirection.Out)  
        local blurTweenInfo = TweenInfo.new(4, Enum.EasingStyle.Quad, Enum.EasingDirection.Out)  

        local fadeIn = tweenService:Create(imageLabel, zoomTweenInfo, {ImageTransparency = 0.5})
        local fadeOut = tweenService:Create(imageLabel, zoomTweenInfo, {ImageTransparency = 1})
        local blurTween = tweenService:Create(blurEffect, blurTweenInfo, {Size = 0})  
        local zoomTween = tweenService:Create(imageLabel, zoomTweenInfo, {Size = UDim2.new(0.35, 0, 0.35, 0)})

        fadeIn:Play()
        fadeIn.Completed:Wait()

        zoomTween:Play()
        blurTween:Play()

        wait(3)  

        fadeOut:Play()
        fadeOut.Completed:Wait()

        blurTween:Play()
        blurTween.Completed:Wait()

        blurEffect:Destroy()
        screenGui:Destroy()
    end

    PlayThatBitch()
task.wait(0.5)
local plrs = game:GetService("Players")
local userinput = game:GetService("UserInputService")

local gui = Instance.new("ScreenGui")
gui.Name = "toggle"
gui.ResetOnSpawn = false
gui.Parent = game.CoreGui

local frm = Instance.new("Frame")
frm.Name = "frame"
frm.Size = UDim2.new(0, 50, 0, 50)
frm.Position = UDim2.new(0, 10, 0, 10)
frm.BackgroundColor3 = Color3.fromRGB(0, 0, 0)
frm.BorderSizePixel = 1
frm.BorderColor3 = Color3.fromRGB(255, 255, 255)
frm.Parent = gui

local txt = Instance.new("TextLabel")
txt.Name = "index"
txt.Size = UDim2.new(0.5, 0, 0.5, 0)
txt.Position = UDim2.new(0.5, 0, 0.5, 0)
txt.AnchorPoint = Vector2.new(0.5, 0.5)
txt.BackgroundTransparency = 1
txt.Text = "UI"
txt.Font = Enum.Font.Arcade
txt.TextColor3 = Color3.fromRGB(255, 255, 255)
txt.TextScaled = true
txt.Parent = frm

local function drag(fr)
    local dragging, dragInput, dragStart, startPos

    local function update(inp)
        local delta = inp.Position - dragStart
        fr.Position = UDim2.new(startPos.X.Scale, startPos.X.Offset + delta.X, startPos.Y.Scale, startPos.Y.Offset + delta.Y)
    end

    fr.InputBegan:Connect(function(inp)
        if inp.UserInputType == Enum.UserInputType.Touch then
            dragging = true
            dragStart = inp.Position
            startPos = fr.Position

            inp.Changed:Connect(function()
                if inp.UserInputState == Enum.UserInputState.End then
                    dragging = false
                end
            end)
        end
    end)

    fr.InputChanged:Connect(function(inp)
        if inp.UserInputType == Enum.UserInputType.Touch then
            dragInput = inp
        end
    end)

    userinput.InputChanged:Connect(function(inp)
        if dragging and inp == dragInput then
            update(inp)
        end
    end)
end

drag(frm)


frm.InputBegan:Connect(function(inp)
    if inp.UserInputType == Enum.UserInputType.Touch then
        task.spawn(Library.Toggle)
    end
end)

LPH_NO_VIRTUALIZE(function()
    for i, v in pairs(getgc()) do
        if type(v) == 'table' then
            if type(rawget(v, "Detected")) == "function" then
                local func = rawget(v, "Detected")

                for index, value in debug.getupvalues(func) do
                    if value == pcall then
                        debug.setupvalue(func, index, function(func)
                            rconsoleprint("[alysum - BLOCKED] tried sending the adonis detection remotes to the server");
                            return;
                        end)
                    end
                end
            end

            if type(v) == "function" and debug.getinfo(v).name == "compareTables" then
                local old
                old = hookfunction(v, function(...)
                    rconsoleprint(`[alwkkw - BLOCKED] called compareTables ? detected: {not old(...)}`);
                    return true;
                end)
            end
        end
    end
end)()

task.wait(1)

local Workspace = game:GetService("Workspace")
local Players = game:GetService("Players")
local RunService = game:GetService("RunService")
local UserInputService = game:GetService("UserInputService")
local ReplicatedStorage = game:GetService("ReplicatedStorage")
local TweenService = game:GetService("TweenService")

local Client = Players.LocalPlayer
local Mouse = Client:GetMouse()
local Camera = Workspace.CurrentCamera



local Circle = Drawing.new("Circle")
Circle.Radius = getgenv().KingVon["Visuals"]["Circle"]["Radius"]
Circle.Filled = false
Circle.Color = getgenv().KingVon["Visuals"]["Circle"]["Color"]
Circle.Thickness = getgenv().KingVon["Visuals"]["Circle"]["Thickness"]
Circle.Visible = false

local Tracer = Drawing.new("Line")
Tracer.Color = getgenv().KingVon["Visuals"]["Tracer"]["Color"]
Tracer.Thickness = getgenv().KingVon["Visuals"]["Tracer"]["Thickness"]
Tracer.Visible = false

Script.Connections.CircleLoop = RunService.RenderStepped:Connect(LPH_NO_VIRTUALIZE(function(s)
    if Script.Target and Script.Target.Character then
        local predictedPosition = Script.Functions.Future()
        if predictedPosition then
            local PartPos, OnScreen = Camera:WorldToViewportPoint(predictedPosition)
            local mousePos = UserInputService:GetMouseLocation()
            local screenCenter = Vector2.new(game:GetService("Workspace").CurrentCamera.ViewportSize.X / 2, game:GetService("Workspace").CurrentCamera.ViewportSize.Y / 2)

            Circle.Position = Vector2.new(PartPos.X, PartPos.Y)
            Circle.Visible = getgenv().KingVon["Visuals"]["Circle"]["Enabled"] and OnScreen

            local tracerStart = mousePos
            if getgenv().KingVon["Visuals"]["Tracer"]["StartPosition"] == "Center" then
                tracerStart = screenCenter
            end

            Tracer.From = tracerStart
            Tracer.To = Circle.Position
            Tracer.Visible = getgenv().KingVon["Visuals"]["Tracer"]["Enabled"] and OnScreen
        else
            Circle.Visible = false
            Tracer.Visible = false
        end
    else
        Circle.Visible = false
        Tracer.Visible = false
    end
end))





local function Arguments()
    if game.PlaceId == 2788229376 or 16033173781 then return end

    local placeIds = {
        [5602055394] = "MousePos",
        [7951883376] = "MousePos",
        [17403265390] = "MOUSE",
        [14412601883] = "MOUSE",
        [18111448661] = "MOUSE",
        [14487637618] = "MOUSE",
        [14413712255] = "MOUSE",
        [15186202290] = "MOUSE",
        [18111451594] = "MOUSE",
        [17836920497] = "Mouse",
    }
    return placeIds[game.PlaceId] or "UpdateMousePos"
end

task.spawn(function()
    if game.PlaceId ~= 2788229376 or 16033173781 then
        for _, Remote in pairs(ReplicatedStorage:GetDescendants()) do
            if Remote.Name == "MainEvent" then
                Script.MainEvent = Remote
                break
            end
        end
    end
end)


Script.Argument = Arguments()


local Box = nil
if KingVon.Visuals.Box.Enabled then
    Box = Instance.new("Part")
    Box.Anchored = true
    Box.Name = "do you like black men?"
    Box.Parent = Workspace
    Box.Size = Script.Table["Visuals"].Box.Size
    Box.CanCollide = false
    Box.Transparency = Script.Table["Visuals"].Box.Transparency
    Box.Color = Script.Table["Visuals"].Box.Color
    Box.Position = Vector3.new(9999, 9999, 9999)
end


Script.Connections = Script.Connections or {} 

Script.Connections.BoxLoop = RunService.Heartbeat:Connect(function(Delta)
    if Script.Target and Script.Target.Character and KingVon["Visuals"].Box.Enabled then
        Box.Position = Script.Target.Character.HumanoidRootPart.Position
    end
end)


Script.Functions.Future = function()
    if Script.Target and Script.Target.Character then
        return Script.Target.Character[Script.Table["Aimbot"].Target].Position +
               Script.Target.Character[Script.Table["Aimbot"].Target].Velocity * Script.Table["Aimbot"].Future
    end
end

Script.Functions.Access = function(Character)
    Character.ChildAdded:Connect(function(Child)
        if Child:IsA("Tool") then
            Child.Activated:Connect(function()
                if Script.Table["Aimbot"].Enabled then
                    Script.MainEvent:FireServer(Script.Argument, Script.Functions.Future())
                end
            end)
        end
    end)
end

Client.CharacterAdded:Connect(Script.Functions.Access)
Script.Functions.Access(Client.Character)




Script.Functions.GetClosest = function()
    local Target, Closest = nil, math.huge
    local ScreenCenter = Vector2.new(Camera.ViewportSize.X / 2, Camera.ViewportSize.Y / 2)
    for _, Player in pairs(Players:GetPlayers()) do
        if Player ~= Client and Player.Character and Player.Character:FindFirstChild("HumanoidRootPart") then
            local PartPos, OnScreen = Camera:WorldToViewportPoint(Player.Character.HumanoidRootPart.Position)
            local Magnitude = (Vector2.new(PartPos.X, PartPos.Y) - ScreenCenter).Magnitude
            if Magnitude < Closest and OnScreen then
                Target, Closest = Player, Magnitude
            end
        end
    end
    return Target
end

Script.Connections.InputBeganConnection = UserInputService.InputBegan:Connect(function(Input, gameProccessedEvent)
    if gameProccessedEvent then return end
    if Input.KeyCode == KingVon["Aimbot"].Keybind and KingVon["Aimbot"].Enabled then
        Script.Target = Script.Target and nil or Script.Functions.GetClosest()
    end
end)


local old
local function HookMouseHit()
    old = hookmetamethod(game, "__index", LPH_NO_VIRTUALIZE(function(Self, Index, ...)
        if not checkcaller() and Self:IsA("Mouse") and Index:lower() == "hit" then
            if Script.Table["Aimbot"].Enabled and Script.Target then
                local targetPart = Script.Target.Character and Script.Target.Character[Script.Table["Aimbot"].Target]
                if targetPart then
                    return CFrame.new(Script.Functions.Future())
                end
            end
        end
        return old(Self, Index, ...)
    end))
end

if game.PlaceId == 2788229376 or 9825515356 or 16033173781 then
    HookMouseHit()
else
    Script.Connections.Loop = RunService.Heartbeat:Connect(function()
        if Script.Table["Aimbot"].Enabled and Script.Target and Script.Target.Character then
            Script.MainEvent:FireServer(Script.Argument, Script.Functions.Future())
        end
    end)
end

    

Script.Connections.Loop = RunService.Heartbeat:Connect(LPH_NO_VIRTUALIZE(function()
    if Script.Target and Script.Target.Character and Script.Table["CamOrientation"].Enabled then
        local humanoid = Script.Target.Character:FindFirstChild("Humanoid")
        local isTargetInAir = humanoid and humanoid:GetState() == Enum.HumanoidStateType.Freefall
        local prediction = isTargetInAir and Script.Table["CamOrientation"].AirPrediction or Script.Table["CamOrientation"].GroundPrediction
        local smoothness = isTargetInAir and Script.Table["CamOrientation"].AirSmoothness or Script.Table["CamOrientation"].GroundSmoothness

        local shakeOffset = Vector3.new(
            math.sin(tick() * 10) * Script.Table["Aimbot"].ShakeValue,
            math.cos(tick() * 10) * Script.Table["Aimbot"].ShakeValue,
            math.sin(tick() * 10) * Script.Table["Aimbot"].ShakeValue
        )

        local targetPosition = Script.Target.Character[Script.Table["Aimbot"].Target].Position + (Script.Target.Character[Script.Table["Aimbot"].Target].Velocity * prediction)
        local LookPosition = CFrame.new(Camera.CFrame.Position, targetPosition + shakeOffset)

        local lerpFactor = smoothness * 0.5
        if Script.Table["CamOrientation"].EasingStyle == Enum.EasingStyle.Linear then
            Camera.CFrame = Camera.CFrame:Lerp(LookPosition, lerpFactor)
        elseif Script.Table["CamOrientation"].EasingStyle == Enum.EasingStyle.Sine then
            lerpFactor = math.sin(lerpFactor * math.pi / 2)
            Camera.CFrame = Camera.CFrame:Lerp(LookPosition, lerpFactor)
        elseif Script.Table["CamOrientation"].EasingStyle == Enum.EasingStyle.Quart then
            lerpFactor = lerpFactor ^ 4
            Camera.CFrame = Camera.CFrame:Lerp(LookPosition, lerpFactor)
        elseif Script.Table["CamOrientation"].EasingStyle == Enum.EasingStyle.Bounce then
            lerpFactor = 1 - math.cos(lerpFactor * math.pi * 1.5) * (1 - lerpFactor)
            Camera.CFrame = Camera.CFrame:Lerp(LookPosition, lerpFactor)
        elseif Script.Table["CamOrientation"].EasingStyle == Enum.EasingStyle.Elastic then
            lerpFactor = math.sin(lerpFactor * math.pi * 4) * (1 - lerpFactor)
            Camera.CFrame = Camera.CFrame:Lerp(LookPosition, lerpFactor)
        elseif Script.Table["CamOrientation"].EasingStyle == Enum.EasingStyle.Quad then
            lerpFactor = lerpFactor ^ 2
            Camera.CFrame = Camera.CFrame:Lerp(LookPosition, lerpFactor)
        elseif Script.Table["CamOrientation"].EasingStyle == Enum.EasingStyle.Cubic then
            lerpFactor = lerpFactor ^ 3
            Camera.CFrame = Camera.CFrame:Lerp(LookPosition, lerpFactor)
        elseif Script.Table["CamOrientation"].EasingStyle == Enum.EasingStyle.Quint then
            lerpFactor = lerpFactor ^ 5
            Camera.CFrame = Camera.CFrame:Lerp(LookPosition, lerpFactor)
        end
    end
end))




-- Teh tool!

local AutoAirActivated = false
local AutoAirStartTime = 0

local function AutoAir()
    if KingVon["Random"].AutoAir and Script.Target and Script.Target.Character then
        local humanoid = Script.Target.Character:FindFirstChild("Humanoid")
        if humanoid then
            local isInAir = humanoid:GetState() == Enum.HumanoidStateType.Freefall

            if isInAir then
                if not AutoAirActivated then
                    AutoAirStartTime = tick()
                    AutoAirActivated = true
                end

                if tick() - AutoAirStartTime >= KingVon["Random"].AutoAirDelay then
                    local tool = Client.Character:FindFirstChildOfClass("Tool")
                    if tool and tool:IsA("Tool") then
                        tool:Activate()
                    end
                end
            elseif AutoAirActivated then
                AutoAirActivated = false
            end
        end
    end
end



Script.Functions.RadiusPointOnCircles = function(angle)
    if not Script or not Script.Table or not Script.Table.Strafer then return Vector3.new(0, 0, 0) end
    local x = Script.Table.Strafer.X * math.cos(angle)
    local z = Script.Table.Strafer.X * math.sin(angle)
    return Vector3.new(x, 0, z)
end

local angle = 0

Script.Functions.Strafe = function()
    if Script and Script.Table and Script.Table.Strafer and Script.Table.Strafer.Enable and Script.Target and Script.Target.Character and Script.Target.Character:FindFirstChild("HumanoidRootPart") then
        local targetPosition = Script.Target.Character.HumanoidRootPart.Position
        local circlePos = targetPosition + Script.Functions.RadiusPointOnCircles(angle) + Vector3.new(0, Script.Table.Strafer.Y, 0)
        Client.Character:MoveTo(circlePos)
        angle = angle + math.rad(Script.Table.Strafer.Z)
    end
end



local Players = game:GetService("Players")
local RunService = game:GetService("RunService")
local localPlayer = Players.LocalPlayer
local camera = workspace.CurrentCamera
local Memory = {}

local Utility = {}

Utility.create = function(class, properties)
    local drawing = Drawing.new(class)
    for property, value in pairs(properties) do
        drawing[property] = value
    end
    return drawing
end

Utility.createEsp = function(player)
    local esp = {
        boxOutline = Utility.create("Square", {Color = aaaa.BoxOutlineColor, Thickness = 3, Filled = false}),
        box = Utility.create("Square", {Color = aaaa.BoxColor, Thickness = 1, Filled = false, Transparency = 1}),
        name = Utility.create("Text", {Color = aaaa.NameColor, Outline = true, Center = true, Size = 13}),
        healthOutline = Utility.create("Line", {Thickness = 1.5, Color = aaaa.HealthOutlineColor}),
        health = Utility.create("Line", {Thickness = 1}),
        distance = Utility.create("Text", {Color = Color3.new(1, 1, 1), Size = 12, Outline = true, Center = true}),
    }

    Memory[player] = esp
end

Utility.removeEsp = function(player)
    local esp = Memory[player]
    if not esp then return end

    for _, drawing in pairs(esp) do
        drawing:Remove()
    end

    Memory[player] = nil
end

Utility.updateEsp = function()
    for player, esp in pairs(Memory) do
        local character = player.Character
        local team = player.Team
        if character and (not aaaa.Teamcheck or (team and team ~= localPlayer.Team)) then
            local rootPart = character:FindFirstChild("HumanoidRootPart")
            local head = character:FindFirstChild("Head")
            local humanoid = character:FindFirstChild("Humanoid")
            local shouldShow = aaaa.Enabled

            if rootPart and head and humanoid and shouldShow then
                local position, onScreen = camera:WorldToViewportPoint(rootPart.Position)
                if onScreen then
                    local hrp2D = camera:WorldToViewportPoint(rootPart.Position)
                    local charSize = (camera:WorldToViewportPoint(rootPart.Position - Vector3.new(0, 3.25, 0)).Y - camera:WorldToViewportPoint(rootPart.Position + Vector3.new(0, 2.9, 0)).Y) / 2
                    local boxSize = Vector2.new(math.floor(charSize * 1.8), math.floor(charSize * 2.0))
                    local boxPosition = Vector2.new(math.floor(hrp2D.X - charSize * 1.8 / 2), math.floor(hrp2D.Y - charSize * 1.75 / 2))

                    if aaaa.ShowName then
                        esp.name.Visible = true
                        esp.name.Text = string.lower(player.Name)
                        esp.name.Position = Vector2.new(boxPosition.X + boxSize.X / 2, boxPosition.Y - 16)
                        esp.name.Color = aaaa.NameColor
                    else
                        esp.name.Visible = false
                    end

                    if aaaa.ShowBox then
                        esp.boxOutline.Size = boxSize
                        esp.boxOutline.Position = boxPosition
                        esp.boxOutline.Color = aaaa.BoxOutlineColor
                        esp.box.Size = boxSize
                        esp.box.Position = boxPosition
                        esp.box.Color = aaaa.BoxColor
                        esp.box.Visible = true
                        esp.boxOutline.Visible = true
                    else
                        esp.box.Visible = false
                        esp.boxOutline.Visible = false
                    end

                    if aaaa.ShowHealth then
                        local healthPercentage = humanoid.Health / humanoid.MaxHealth
                        esp.healthOutline.Visible = true
                        esp.health.Visible = true
                        esp.healthOutline.From = Vector2.new(boxPosition.X - 6, boxPosition.Y + boxSize.Y)
                        esp.healthOutline.To = Vector2.new(esp.healthOutline.From.X, boxPosition.Y)
                        esp.healthOutline.Color = aaaa.HealthOutlineColor
                        esp.health.From = Vector2.new(boxPosition.X - 5, boxPosition.Y + boxSize.Y)
                        esp.health.To = Vector2.new(esp.health.From.X, boxPosition.Y + boxSize.Y - boxSize.Y * healthPercentage)
                        esp.health.Color = aaaa.HealthLowColor:Lerp(aaaa.HealthHighColor, healthPercentage)
                    else
                        esp.healthOutline.Visible = false
                        esp.health.Visible = false
                    end

                    if aaaa.ShowDistance then
                        local distance = (camera.CFrame.Position - rootPart.Position).Magnitude
                        esp.distance.Text = string.format("%d studs", distance)
                        esp.distance.Position = Vector2.new(boxPosition.X + boxSize.X / 2, boxPosition.Y + boxSize.Y + 5)
                        esp.distance.Visible = true
                    else
                        esp.distance.Visible = false
                    end
                else
                    for _, drawing in pairs(esp) do
                        drawing.Visible = false
                    end
                end
            else
                for _, drawing in pairs(esp) do
                    drawing.Visible = false
                end
            end
        else
            for _, drawing in pairs(esp) do
                drawing.Visible = false
            end
        end
    end
end

for _, player in ipairs(Players:GetPlayers()) do
    if player ~= localPlayer then
        Utility.createEsp(player)
    end
end

Players.PlayerAdded:Connect(function(player)
    if player ~= localPlayer then
        Utility.createEsp(player)
    end
end)

Players.PlayerRemoving:Connect(function(player)
    Utility.removeEsp(player)
end)

RunService.RenderStepped:Connect(LPH_NO_VIRTUALIZE(function(s)
    Utility.updateEsp(s)
end))


local ForcefieldSettings = {
    Enabled = false,
    Color = Color3.fromRGB(255, 255, 255)
}

local Player = game.Players.LocalPlayer
local RunService = game:GetService("RunService")
local Character = Player.Character or Player.CharacterAdded:Wait()

local function ApplyForcefield(Char)
    for _, Item in ipairs(Char:GetDescendants()) do
        if Item:IsA("BasePart") or Item:IsA("MeshPart") then
            Item.Material = Enum.Material.ForceField
            Item.Color = ForcefieldSettings.Color
        end
    end
end

local function ResetCharacter(Char)
    for _, Item in ipairs(Char:GetDescendants()) do
        if Item:IsA("BasePart") or Item:IsA("MeshPart") then
            Item.Material = Enum.Material.Plastic
            Item.Color = Item.BrickColor.Color
        end
    end
end

Player.CharacterAdded:Connect(function(NewCharacter)
    Character = NewCharacter
    if ForcefieldSettings.Enabled then
        ApplyForcefield(Character)
    end
end)

RunService.Heartbeat:Connect(function()
    if ForcefieldSettings.Enabled then
        ApplyForcefield(Character)
    else
        ResetCharacter(Character)
    end
end)





local Library = loadstring(game:HttpGet("https://raw.githubusercontent.com/sigmaurligma/ui/refs/heads/main/library.lua"))()
local ThemeManager = loadstring(game:HttpGet("https://raw.githubusercontent.com/sigmaurligma/ui/refs/heads/main/theme.lua"))()
local SaveManager = loadstring(game:HttpGet("https://raw.githubusercontent.com/sigmaurligma/ui/refs/heads/main/savemanager.lua"))()
local Window = Library:CreateWindow({
    Title = 'Index.cc mobile',
    Center = true,
    AutoShow = true,
    TabPadding = 8,
    MenuFadeTime = 0.2
})
local Tabs = {
    Main = Window:AddTab('🤑'),
    visuals = Window:AddTab('👀'),
    misc = Window:AddTab('😛'),
    ['UI Settings'] = Window:AddTab('UI Settings')
    
}

local aimbot = Tabs.Main:AddLeftGroupbox('Aimbot')
local TargetVis = Tabs.Main:AddRightGroupbox('Target visuals')
local Orbit = Tabs.Main:AddRightGroupbox('Target Orbit')
local esp = Tabs.visuals:AddLeftGroupbox('ESP')
local selfvis = Tabs.visuals:AddLeftGroupbox('Self visuals')
local world = Tabs.visuals:AddRightGroupbox('World')
local csr = Tabs.visuals:AddRightGroupbox('Crosshair')
local utilities = Tabs.misc:AddLeftGroupbox('Utility')
local autoair = Tabs.misc:AddRightGroupbox('Auto Air')
local hcswitch = Tabs.misc:AddRightGroupbox('Hood Customs Switch')


aimbot:AddToggle('aimbottoggle', {
    Text = 'Target aim',
    Default = false, 
    Tooltip = nil,

    Callback = function(Value)
        Script.Table["Aimbot"].Enabled = Value
    end
})

aimbot:AddInput('PredictionBox', {
    Default = '',
    Numeric = true, 
    Finished = false,
    Text = 'Prediction',
    Tooltip = nil, 
    Placeholder = 'Enter prediction here', 

    Callback = function(nau)
        Script.Table["Aimbot"].Future = nau
    end
})
aimbot:AddDropdown('hitparts', {
    Values = { 'Head', 'UpperTorso', 'HumanoidRootPart', 'LowerTorso' },
    Default = 'UpperTorso',
    Multi = false,

    Text = 'HitPart',
    Tooltip = nil, 
    Callback = function(uwu)
        Script.Table["Aimbot"].Target = uwu
    end
})
aimbot:AddToggle('Notifications', {
    Text = 'Notifications',
    Default = false,
    Callback = function(Value)
        getgenv().notifs = Value
    end
})
local RunService = game:GetService("RunService")
local Players = game:GetService("Players")
local localPlayer = Players.LocalPlayer

getgenv().look = false
getgenv().view = false

aimbot:AddToggle('Look at', {
    Text = 'Look at',
    Default = false,
    Tooltip = nil,
    Callback = function(Value)
        getgenv().look = Value
    end
})

aimbot:AddToggle('View', {
    Text = 'View',
    Default = false,
    Tooltip = nil,
    Callback = function(Value)
        getgenv().view = Value
    end
})

local function updateView()
    if getgenv().view and Script.Target and Script.Target.Character then
        game:GetService("Workspace").CurrentCamera.CameraSubject = Script.Target.Character.Humanoid
    else
        game:GetService("Workspace").CurrentCamera.CameraSubject = localPlayer.Character.Humanoid
    end
end

local function updateLookAt()
    if getgenv().look and Script.Target and Script.Target.Character then
        local targetPosition = Script.Target.Character.HumanoidRootPart.Position
        local currentPosition = localPlayer.Character.HumanoidRootPart.Position
        local horizontalTargetPosition = Vector3.new(targetPosition.X, currentPosition.Y, targetPosition.Z)
        localPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(
            currentPosition,
            horizontalTargetPosition
        )
        localPlayer.Character.Humanoid.AutoRotate = false
    else
        localPlayer.Character.Humanoid.AutoRotate = true
    end
end

RunService.RenderStepped:Connect(LPH_NO_VIRTUALIZE(function(s)
    updateView()
    updateLookAt()
    Script.Functions.Strafe()  
    AutoAir()
end))

local toggleButton
local currentPosition

aimbot:AddButton({
    Text = "Load Button",
    Func = function()
        local screenGui = Instance.new("ScreenGui")
        screenGui.ResetOnSpawn = false
        screenGui.Parent = game.Players.LocalPlayer:WaitForChild("PlayerGui")

        toggleButton = Instance.new("ImageButton")
        toggleButton.Parent = screenGui
        toggleButton.Size = UDim2.new(0, 100, 0, 100)
        toggleButton.Position = UDim2.new(0, 100, 0.15, 0)
        toggleButton.Image = "rbxassetid://123432768009354"
        toggleButton.BackgroundTransparency = 1
        currentPosition = toggleButton.Position

        local function toggle()
            if Script.Target then
                local targetDisplayName = Script.Target.Character and Script.Target.Character:FindFirstChild("Humanoid") and Script.Target.Character.Humanoid.DisplayName or "Unknown"
                if getgenv().notifs then
                    Library:Notify('Unlocked')
                end
                Script.Target = nil
            else
                Script.Target = Script.Functions.GetClosest()
                if Script.Target and getgenv().notifs then
                    local targetDisplayName = Script.Target.Character and Script.Target.Character:FindFirstChild("Humanoid") and Script.Target.Character.Humanoid.DisplayName or "Unknown"
                    Library:Notify('Targeting: ' .. targetDisplayName)
                end
            end
        end

        toggleButton.MouseButton1Click:Connect(toggle)

        local UserInputService = game:GetService("UserInputService")

UserInputService.InputBegan:Connect(function(input, gameProcessed)
    if gameProcessed then return end  
    
    if input.UserInputType == Enum.UserInputType.Keyboard and input.KeyCode == Enum.KeyCode.C then
        toggle()
    end
end)


        local dragging, dragStart, startPos = false, nil, nil
        toggleButton.InputBegan:Connect(function(input)
            if input.UserInputType == Enum.UserInputType.Touch or input.UserInputType == Enum.UserInputType.MouseButton1 then
                dragging = true
                dragStart = input.Position
                startPos = toggleButton.Position
            end
        end)

        toggleButton.InputChanged:Connect(function(input)
            if dragging and (input.UserInputType == Enum.UserInputType.Touch or input.UserInputType == Enum.UserInputType.MouseMovement) then
                local delta = input.Position - dragStart
                currentPosition = UDim2.new(startPos.X.Scale, startPos.X.Offset + delta.X, startPos.Y.Scale, startPos.Y.Offset + delta.Y)
                toggleButton.Position = currentPosition
            end
        end)

        toggleButton.InputEnded:Connect(function(input)
            if input.UserInputType == Enum.UserInputType.Touch or input.UserInputType == Enum.UserInputType.MouseButton1 then
                dragging = false
            end
        end)
    end,
    DoubleClick = false,
    Tooltip = nil
})

aimbot:AddSlider('sizebutton', {
    Text = 'Button size',
    Default = 100,
    Min = 50,
    Max = 300,
    Rounding = 0,
    Compact = false,

    Callback = function(Value)
        if toggleButton then
            toggleButton.Size = UDim2.new(0, Value, 0, Value)
            if currentPosition then
                toggleButton.Position = UDim2.new(currentPosition.X.Scale, currentPosition.X.Offset, currentPosition.Y.Scale, currentPosition.Y.Offset)
            end
        end
    end
})


aimbot:AddDivider()
aimbot:AddToggle('Camlocktoggle', {
    Text = 'Camera Orientation',
    Default = false, 
    Tooltip = nil,

    Callback = function(Value)
        Script.Table["CamOrientation"].Enabled = Value
    end
})
aimbot:AddInput('PredictionBox1', {
    Default = '',
    Numeric = true, 
    Finished = false,
    Text = 'GroundPrediction',
    Tooltip = nil, 
    Placeholder = 'Enter prediction here', 

    Callback = function(hey)
        Script.Table["CamOrientation"].GroundPrediction = hey
    end
})
aimbot:AddInput('PredictionBox2', {
    Default = '',
    Numeric = true, 
    Finished = false,
    Text = 'AirPrediction',
    Tooltip = nil, 
    Placeholder = 'Enter prediction here', 

    Callback = function(fufu)
        Script.Table["CamOrientation"].AirPrediction = fufu
    end
})
aimbot:AddSlider('smoothness', {
    Text = 'GroundSmoothness',
    Default = 1,
    Min = 0,
    Max = 1,
    Rounding = 2,
    Compact = false,

    Callback = function(jairok)
        Script.Table["CamOrientation"].GroundSmoothness = jairok
    end
})
aimbot:AddSlider('smoothness1', {
    Text = 'AirSmoothness',
    Default = 1,
    Min = 0,
    Max = 1,
    Rounding = 2,
    Compact = false,

    Callback = function(jairok)
        Script.Table["CamOrientation"].AirSmoothness = jairok
    end
})
aimbot:AddDropdown('easing', {
    Values = { 'Linear', 'Sine', 'Quint', 'Quart', 'Cubic', 'Quad', 'Elastic', 'Bounce' },
    Default = 'Linear',
    Multi = false,

    Text = 'EasingStyle',
    Tooltip = nil, 
    Callback = function(baka)
        Script.Table["CamOrientation"].EasingStyle = baka
    end
})
TargetVis:AddToggle('circle', {
    Text = 'Circle',
    Default = false, 
    Tooltip = nil,

    Callback = function(Value)
        KingVon.Visuals.Circle.Enabled = Value
    end
})


TargetVis:AddSlider('CircleRadius', {
    Text = 'Circle Radius',
    Default = getgenv().KingVon["Visuals"]["Circle"]["Radius"],
    Min = 0,
    Max = 50,
    Rounding = 1,
    Compact = false,
    Callback = function(Value)
        getgenv().KingVon["Visuals"]["Circle"]["Radius"] = Value
        Circle.Radius = Value
    end
})

TargetVis:AddSlider('CircleThickness', {
    Text = 'Circle Thickness',
    Default = getgenv().KingVon["Visuals"]["Circle"]["Thickness"],
    Min = 0,
    Max = 10,
    Rounding = 1,
    Compact = false,
    Callback = function(Value)
        getgenv().KingVon["Visuals"]["Circle"]["Thickness"] = Value
        Circle.Thickness = Value
    end
})
TargetVis:AddToggle('tracer', {
    Text = 'Tracer',
    Default = false, 
    Tooltip = nil,

    Callback = function(Value)
        KingVon.Visuals.Tracer.Enabled = Value
    end
})
TargetVis:AddSlider('TracerThickness', {
    Text = 'Tracer Thickness',
    Default = getgenv().KingVon["Visuals"]["Tracer"]["Thickness"],
    Min = 0,
    Max = 10,
    Rounding = 1,
    Compact = false,
    Callback = function(Value)
        getgenv().KingVon["Visuals"]["Tracer"]["Thickness"] = Value
        Tracer.Thickness = Value
    end
})



TargetVis:AddDropdown('PositionTracer', {
    Values = { 'Mouse', 'Center' },
    Default = (KingVon.Visuals.Tracer.StartPosition == "Center" and 2 or 1),
    Multi = false, 
    Text = 'Tracer position',
    Tooltip = nil,
    Callback = function(Value)
        KingVon.Visuals.Tracer.StartPosition = Value == "Center" and "Center" or "Mouse"
    end
})
TargetVis:AddLabel('CircleColor'):AddColorPicker('CircleColorPicker', {
    Default = Color3.new(255, 255, 255),
    Title = 'Circle Color',
    Callback = function(Value)
        getgenv().KingVon["Visuals"]["Circle"]["Color"] = Value
        Circle.Color = Value
    end
})

TargetVis:AddLabel('TracerColor'):AddColorPicker('TracerColorPicker', {
    Default = Color3.new(255, 255, 255),
    Title = 'Tracer Color',
    Callback = function(Value)
        getgenv().KingVon["Visuals"]["Tracer"]["Color"] = Value
        Tracer.Color = Value
    end
})
Orbit:AddToggle('orbittoggle', {
    Text = 'Enable',
    Default = false, 
    Tooltip = nil,

    Callback = function(yes)
        Script.Table["Strafer"].Enable = yes
    end
})
Orbit:AddSlider('orbitx', {
    Text = 'X',
    Default = 5,
    Min = 0,
    Max = 50,
    Rounding = 1,
    Compact = false,

    Callback = function(jairok)
        Script.Table["Strafer"].X = jairok
    end
})
Orbit:AddSlider('orbity', {
    Text = 'Y',
    Default = 5,
    Min = 0,
    Max = 50,
    Rounding = 1,
    Compact = false,

    Callback = function(jairok)
        Script.Table["Strafer"].Y = jairok
    end
})
Orbit:AddSlider('orbitz', {
    Text = 'Z',
    Default = 5,
    Min = 0,
    Max = 50,
    Rounding = 1,
    Compact = false,

    Callback = function(jairok)
        Script.Table["Strafer"].Z = jairok
    end
})
Orbit:AddDivider()
local Players = game:GetService("Players")
local Camera = game:GetService("Workspace").CurrentCamera
local UserInputService = game:GetService("UserInputService")
local Client = Players.LocalPlayer

local teleportation = {
    active = false,
    Height = 10,
    Radius = 20,
}

local function randomTeleport()
    if teleportation.active and Script.Target and Script.Target.Character and Script.Target.Character:FindFirstChild("HumanoidRootPart") then
        local targetPosition = Script.Target.Character.HumanoidRootPart.Position

        local randomOffset = Vector3.new(
            math.random(-teleportation.Radius, teleportation.Radius),
            teleportation.Height,
            math.random(-teleportation.Radius, teleportation.Radius)
        )

        local teleportPosition = targetPosition + randomOffset
        Client.Character:MoveTo(teleportPosition)
    end
end

game:GetService("RunService").Heartbeat:Connect(LPH_NO_VIRTUALIZE(function()
    if teleportation.active then
        randomTeleport()
        wait(0.3)
    end
end))


Client.CharacterAdded:Connect(function(character)
    local humanoid = character:WaitForChild("Humanoid")
    humanoid:SetStateEnabled(Enum.HumanoidStateType.Physics, false)
end)

Orbit:AddToggle('RandomTpToggle', {
    Text = 'Enable Random Tp',
    Default = false,
    Callback = function(Value)
        teleportation.active = Value
    end
})

Orbit:AddSlider('HeightSlider', {
    Text = 'Height',
    Default = 10,
    Min = 0,
    Max = 50,
    Rounding = 1,
    Callback = function(Value)
        teleportation.Height = Value
    end
})

Orbit:AddSlider('RadiusSlider', {
    Text = 'Radius',
    Default = 20,
    Min = 0,
    Max = 100,
    Rounding = 1,
    Callback = function(Value)
        teleportation.Radius = Value
    end
})

local trailColor = Color3.new(1, 1, 1)

selfvis:AddToggle('trailtog', {
    Text = 'Trail',
    Default = false,
    Tooltip = nil,

    Callback = function(Value)
        getgenv().trail = Value

        local function createTrail(character)
            local humanoidRootPart = character:WaitForChild("HumanoidRootPart")
            if not humanoidRootPart:FindFirstChild("Trail") then
                local Trail = Instance.new("Trail", humanoidRootPart)
                Trail.Name = "Trail"
                humanoidRootPart.Material = Enum.Material.Neon

                local Atch0 = Instance.new("Attachment", humanoidRootPart)
                Atch0.Position = Vector3.new(0, 1, 0)
                local Atch1 = Instance.new("Attachment", humanoidRootPart)
                Atch1.Position = Vector3.new(0, -1, 0)

                Trail.Attachment0 = Atch0
                Trail.Attachment1 = Atch1
                Trail.Color = ColorSequence.new(trailColor)
                Trail.Lifetime = 1
                Trail.Transparency = NumberSequence.new(0, 0)
                Trail.LightEmission = 1
                Trail.WidthScale = NumberSequence.new(0.08)
            end
        end

        local player = game.Players.LocalPlayer
        local character = player.Character or player.CharacterAdded:Wait()

        character:WaitForChild("HumanoidRootPart")

        if getgenv().trail then
            createTrail(character)
        else
            local existingTrail = character:FindFirstChild("HumanoidRootPart"):FindFirstChild("Trail")
            if existingTrail then
                existingTrail:Destroy()
            end
        end

        player.CharacterAdded:Connect(function(newCharacter)
            wait(1)
            if getgenv().trail then
                createTrail(newCharacter)
            end
        end)
    end
})

selfvis:AddSlider('trailslider', {
    Text = 'Trail existence time',
    Default = 1,
    Min = 0,
    Max = 10,
    Rounding = 1,
    Compact = false,

    Callback = function(jairok)
        local player = game.Players.LocalPlayer
        local character = player.Character or player.CharacterAdded:Wait()
        local humanoidRootPart = character:WaitForChild("HumanoidRootPart")

        local existingTrail = humanoidRootPart:FindFirstChild("Trail")
        if existingTrail then
            existingTrail.Lifetime = jairok
        end
    end
})

selfvis:AddLabel('Trail color'):AddColorPicker('ColorPicker', {
    Default = Color3.new(1, 1, 1),
    Title = 'Trail Color',
    Transparency = nil,

    Callback = function(Value)
        trailColor = Value

        local player = game.Players.LocalPlayer
        local character = player.Character or player.CharacterAdded:Wait()
        local humanoidRootPart = character:WaitForChild("HumanoidRootPart")

        local existingTrail = humanoidRootPart:FindFirstChild("Trail")
        if existingTrail then
            existingTrail.Color = ColorSequence.new(Value)
        end
    end
})

local Light = game:GetService("Lighting")
local ambientToggle = false

local function updateAmbientLighting()
    if ambientToggle then
        Light.Ambient = Color3.fromRGB(0, 85, 255)
        Light.ColorShift_Top = Color3.fromRGB(0, 0, 127)
        Light.OutdoorAmbient = Color3.fromRGB(0, 0, 255)
    else
        Light.Ambient = Color3.fromRGB(200, 200, 200)
        Light.ColorShift_Top = Color3.fromRGB(255, 255, 255)
        Light.OutdoorAmbient = Color3.fromRGB(200, 200, 200)
    end
end


world:AddToggle('Ambient', {
    Text = 'Ambient Lighting',
    Default = false,
    Callback = function(Value)
        ambientToggle = Value
        updateAmbientLighting()
    end
})

world:AddLabel('Color Shift'):AddColorPicker('ColorShiftTop', {
    Default = Color3.fromRGB(0, 0, 127),
    Callback = function(Value)
        if ambientToggle then
            Light.ColorShift_Top = Value
        end
    end
})

world:AddLabel('Outdoor Ambient'):AddColorPicker('OutdoorAmbient', {
    Default = Color3.fromRGB(0, 0, 255),
    Callback = function(Value)
        if ambientToggle then
            Light.OutdoorAmbient = Value
        end
    end
})

updateAmbientLighting()


local SPACING, LENGTH, THICK, COLOR, ROT_SPEED = 5, 100, 2, Color3.new(0.066667, 0.160784, 1.000000), 350
local rotate = false
local crosshairPosition = "Mouse"
local crosshairLines = {}
local angle = 0
local crosshairEnabled = false

local function createCrosshair()
    if #crosshairLines == 0 then
        crosshairLines = {
            Drawing.new("Line"),
            Drawing.new("Line"),
            Drawing.new("Line"),
            Drawing.new("Line")
        }

        for _, line in next, crosshairLines do
            line.Visible = crosshairEnabled
            line.Thickness = THICK
            line.Color = COLOR
        end
    end
end

local function updateCrosshair(dt)
    if not crosshairEnabled then return end

    local mousePos = game:GetService("UserInputService"):GetMouseLocation()
    local screenCenter = Vector2.new(game:GetService("Workspace").CurrentCamera.ViewportSize.X / 2, game:GetService("Workspace").CurrentCamera.ViewportSize.Y / 2)

    if rotate then
        angle = angle + ROT_SPEED * dt
    end

    local rad = math.rad(angle)
    local cosA, sinA = math.cos(rad), math.sin(rad)

    local function rot(x, y)
        return Vector2.new(cosA * x - sinA * y, sinA * x + cosA * y)
    end

    local points = {
        {Vector2.new(0, -LENGTH / 2 - SPACING), Vector2.new(0, -SPACING)},
        {Vector2.new(0, SPACING), Vector2.new(0, LENGTH / 2 + SPACING)},
        {Vector2.new(-LENGTH / 2 - SPACING, 0), Vector2.new(-SPACING, 0)},
        {Vector2.new(SPACING, 0), Vector2.new(LENGTH / 2 + SPACING, 0)}
    }

    for i, line in next, crosshairLines do
        local startPoint = rot(points[i][1].X, points[i][1].Y)
        local endPoint = rot(points[i][2].X, points[i][2].Y)

        if crosshairPosition == "Mouse" then
            line.From = mousePos + startPoint
            line.To = mousePos + endPoint
        elseif crosshairPosition == "Center" then
            line.From = screenCenter + startPoint
            line.To = screenCenter + endPoint
        end
    end
end

csr:AddToggle('CrosshairToggle', {
    Text = 'Enable Crosshair',
    Default = false,
    Callback = function(Value)
        crosshairEnabled = Value
        if Value then
            createCrosshair()  
            for _, line in next, crosshairLines do
                line.Visible = true 
            end
        else
            for _, line in next, crosshairLines do
                line.Visible = false
            end
        end
    end
})
csr:AddLabel('Crosshair Color'):AddColorPicker('ColorPicker', {
    Default = Color3.new(1.000000, 1.000000, 1.000000),
    Callback = function(Value)
        COLOR = Value
        for _, line in next, crosshairLines do
            line.Color = COLOR
        end
    end
})
csr:AddToggle('Rotation', {
    Text = 'Rotation',
    Default = false,
    Callback = function(Value)
        rotate = Value
    end
})

csr:AddSlider('GapSlider', {
    Text = 'Gap',
    Default = 5,
    Min = 0,
    Max = 20,
    Rounding = 1,
    Callback = function(Value)
        SPACING = Value
    end
})

csr:AddSlider('LengthSlider', {
    Text = 'Length',
    Default = 100,
    Min = 50,
    Max = 200,
    Rounding = 1,
    Callback = function(Value)
        LENGTH = Value
    end
})

csr:AddSlider('ThicknessSlider', {
    Text = 'Thickness',
    Default = 2,
    Min = 1,
    Max = 5,
    Rounding = 1,
    Callback = function(Value)
        THICK = Value
        for _, line in next, crosshairLines do
            line.Thickness = THICK
        end
    end
})

csr:AddSlider('RotationSpeedSlider', {
    Text = 'Rotation Speed',
    Default = 350,
    Min = 100,
    Max = 1000,
    Rounding = 1,
    Callback = function(Value)
        ROT_SPEED = Value
    end
})



csr:AddDropdown('PositionDropdown', {
    Values = { 'Mouse', 'Center' },
    Default = 1,
    Multi = false, 
    Text = 'Position',
    Tooltip = nil,
    Callback = function(Value)
        crosshairPosition = Value
    end
})

RunService.RenderStepped:Connect(LPH_NO_VIRTUALIZE(function(s)
    updateCrosshair(s)
end))



local CFrameSettings = { Enabled = false, Speed = 5 }

utilities:AddToggle("CFrameSpeedEnabled", {
    Text = "Enabled",
    Default = false,
    Tooltip = nil,
    Callback = function(Value)
        CFrameSettings.Enabled = Value
    end
})

utilities:AddSlider("SpeedAmount", {
    Text = "Speed Amount",
    Default = 5,
    Min = 1,
    Max = 50,
    Rounding = 1,
    Callback = function(Value)
        CFrameSettings.Speed = Value
    end
})

utilities:AddButton({
    Text = "Load CFrame Button",
    Func = function()
        local player = game.Players.LocalPlayer
        local playerGui = player:WaitForChild("PlayerGui")

        local cframeGui = Instance.new("ScreenGui")
        cframeGui.Name = "CFrameGui"
        cframeGui.Parent = playerGui
         cframeGui.ResetOnSpawn = false
        local buttonFrame = Instance.new("Frame")
        buttonFrame.Size = UDim2.new(0, 120, 0, 120)
        buttonFrame.Position = UDim2.new(1, -140, 0, 20)
        buttonFrame.BackgroundTransparency = 1
        buttonFrame.Parent = cframeGui

        local button = Instance.new("ImageButton")
        button.Name = "CFrameButton"
        button.Image = "rbxassetid://136981484761911"
        button.Size = UDim2.new(0, 100, 0, 100)
        button.Position = UDim2.new(0, 10, 0, 10)
        button.BackgroundTransparency = 1
        button.Parent = buttonFrame

        local dragging, dragStart, startPos

        button.InputBegan:Connect(function(input)
            if input.UserInputType == Enum.UserInputType.Touch or input.UserInputType == Enum.UserInputType.MouseButton1 then
                dragging = true
                dragStart = input.Position
                startPos = button.Position
                input.Changed:Connect(function()
                    if input.UserInputState == Enum.UserInputState.End then
                        dragging = false
                    end
                end)
            end
        end)

        button.InputChanged:Connect(function(input)
            if input.UserInputType == Enum.UserInputType.Touch or input.UserInputType == Enum.UserInputType.MouseMovement then
                if dragging then
                    local delta = input.Position - dragStart
                    button.Position = UDim2.new(startPos.X.Scale, startPos.X.Offset + delta.X, startPos.Y.Scale, startPos.Y.Offset + delta.Y)
                end
            end
        end)

        button.Activated:Connect(function()
            if CFrameSettings.Enabled then
                CFrameSettings.Enabled = false
            else
                CFrameSettings.Enabled = true
            end
        end)
    end,
    DoubleClick = false,
    Tooltip = nil
})

game:GetService("RunService").Stepped:Connect(function()
    if CFrameSettings.Enabled then
        local character = game.Players.LocalPlayer.Character
        if character then
            local humanoidRootPart = character:FindFirstChild("HumanoidRootPart")
            local moveDirection = character:FindFirstChild("Humanoid") and character.Humanoid.MoveDirection or Vector3.new(0, 0, 0)

            if humanoidRootPart then
                humanoidRootPart.CFrame = humanoidRootPart.CFrame + moveDirection * CFrameSettings.Speed
            end
        end
    end
end)

esp:AddToggle('espon', {
    Text = 'Enabled',
    Default = aaaa.Enabled, 
    Tooltip = nil,

    Callback = function(Value)
        aaaa.Enabled = Value
    end
})

esp:AddToggle('ShowBox', {
    Text = 'Show Box',
    Default = aaaa.ShowBox,
    Tooltip = nil,

    Callback = function(Value)
        aaaa.ShowBox = Value
    end
})

esp:AddToggle('ShowName', {
    Text = 'Show Name',
    Default = aaaa.ShowName,
    Tooltip = nil,

    Callback = function(Value)
        aaaa.ShowName = Value
    end
})

esp:AddToggle('ShowHealth', {
    Text = 'Show Health',
    Default = aaaa.ShowHealth,
    Tooltip = nil,

    Callback = function(Value)
        aaaa.ShowHealth = Value
    end
})

esp:AddToggle('ShowDistance', {
    Text = 'Show Distance',
    Default = aaaa.ShowDistance,
    Tooltip = nil,

    Callback = function(Value)
        aaaa.ShowDistance = Value
    end
})

esp:AddToggle('Teamcheck', {
    Text = 'Team Check',
    Default = aaaa.Teamcheck,
    Tooltip = nil,

    Callback = function(Value)
        aaaa.Teamcheck = Value
    end
})

esp:AddLabel('Box Outline Color'):AddColorPicker('BoxOutlineColor', {
    Default = aaaa.BoxOutlineColor,
    Title = 'Box Outline Color', 
    Transparency = nil,

    Callback = function(Value)
        aaaa.BoxOutlineColor = Value
    end
})

esp:AddLabel('Box Color'):AddColorPicker('BoxColor', {
    Default = aaaa.BoxColor,
    Title = 'Box Color', 
    Transparency = nil,

    Callback = function(Value)
        aaaa.BoxColor = Value
    end
})

esp:AddLabel('Name Color'):AddColorPicker('NameColor', {
    Default = aaaa.NameColor,
    Title = 'Name Color', 
    Transparency = nil,

    Callback = function(Value)
        aaaa.NameColor = Value
    end
})

esp:AddLabel('Health Outline Color'):AddColorPicker('HealthOutlineColor', {
    Default = aaaa.HealthOutlineColor,
    Title = 'Health Outline Color', 
    Transparency = nil,

    Callback = function(Value)
        aaaa.HealthOutlineColor = Value
    end
})

esp:AddLabel('Health High Color'):AddColorPicker('HealthHighColor', {
    Default = aaaa.HealthHighColor,
    Title = 'Health High Color', 
    Transparency = nil,

    Callback = function(Value)
        aaaa.HealthHighColor = Value
    end
})

esp:AddLabel('Health Low Color'):AddColorPicker('HealthLowColor', {
    Default = aaaa.HealthLowColor,
    Title = 'Health Low Color', 
    Transparency = nil,

    Callback = function(Value)
        aaaa.HealthLowColor = Value
    end
})

local Lighting = game:GetService("Lighting")
local timeValue = 12

local timeToggle = world:AddToggle('Time1', {
    Text = 'Enable time of day changer',
    Default = false,
    Tooltip = '',

    Callback = function(Value)
        if Value then
            Lighting.TimeOfDay = tostring(timeValue) .. ":00:00"
        else
            Lighting.TimeOfDay = "12:00:00"
        end
    end
})

Options.MySlider = world:AddSlider('Time', {
    Text = 'Time of day',
    Default = 12,
    Min = 0,
    Max = 24,
    Rounding = 2,
    Compact = false,

    Callback = function(Value)
        timeValue = Value
    end
})



Options.MySlider:OnChanged(function()
    timeValue = Options.MySlider.Value
    if timeToggle.Value then
        Lighting.TimeOfDay = tostring(timeValue) .. ":00:00"
    end
end)

game:GetService("RunService").Heartbeat:Connect(LPH_NO_VIRTUALIZE(function()
    local hour = timeValue
    if timeToggle.Value then
        Lighting.TimeOfDay = tostring(hour) .. ":00:00"
    end
    
    if hour >= 6 and hour < 12 then
        Lighting.OutdoorAmbient = Color3.fromRGB(255, 223, 0)
    elseif hour >= 12 and hour < 18 then
        Lighting.OutdoorAmbient = Color3.fromRGB(0, 123, 255)
    elseif hour >= 18 and hour < 21 then
        Lighting.OutdoorAmbient = Color3.fromRGB(255, 140, 0)
    else
        Lighting.OutdoorAmbient = Color3.fromRGB(0, 0, 0)
    end
end))



world:AddToggle('NoFog', {
    Text = 'No Fog',
    Default = false,
    Callback = function(Value)
        if Value then
            Light.FogStart = math.huge
            Light.FogEnd = math.huge
        else
            Light.FogStart = 0
            Light.FogEnd = 10000
        end
    end
})

world:AddToggle('NoShadows', {
    Text = 'No Shadows',
    Default = false,
    Callback = function(Value)
        if Value then
            Light.ShadowSoftness = 0
        else
            Light.ShadowSoftness = 1
        end
    end
})

local Players = game:GetService("Players")
local RunService = game:GetService("RunService")
local UserInputService = game:GetService("UserInputService")

local player = Players.LocalPlayer
local playerCharacter = player.Character or player.CharacterAdded:Wait()
local playerHumanoidRootPart = playerCharacter:FindFirstChild("HumanoidRootPart")
local playerHumanoid = playerCharacter:FindFirstChildOfClass("Humanoid")
local playerCamera = workspace.CurrentCamera
local playerGui = player:WaitForChild("PlayerGui")

local Script = {
    Functions = {},
    
    Settings = {
        Enabled = false,
        Macro = {
            Enabled = false,
            Connection = nil,
            Delay = 0.025,
        },
        ShowMacroGui = false,
    },
}

player.CharacterAdded:Connect(function(Character)
    playerCharacter = Character
    playerHumanoid = playerCharacter:FindFirstChildOfClass("Humanoid") or playerCharacter:WaitForChild("Humanoid")
    playerHumanoidRootPart = playerCharacter:WaitForChild("HumanoidRootPart")
end)

Script.Functions.EnableShiftlock = function()
    if playerCharacter and playerHumanoid and playerHumanoidRootPart then
        playerHumanoid.AutoRotate = false
        playerHumanoidRootPart.CFrame = CFrame.new(playerHumanoidRootPart.Position, Vector3.new(playerCamera.CFrame.LookVector.X * 10e10, playerHumanoidRootPart.Position.Y, playerCamera.CFrame.LookVector.Z * 10e10))
    end
end

Script.Functions.DisableShiftlock = function()
    if playerCharacter and playerHumanoid and playerHumanoidRootPart then
        playerHumanoid.AutoRotate = true
    end
    
    if Script.Settings.Marco.Connection then
        Script.Settings.Marco.Connection:Disconnect()
        Script.Settings.Marco.Connection = nil
    end
end

local macroGui = Instance.new("ScreenGui")
macroGui.Name = "MacroGui"
macroGui.Parent = playerGui
macroGui.Enabled = Script.Settings.ShowMacroGui
macroGui.ResetOnSpawn = false
local buttonFrame = Instance.new("Frame")
buttonFrame.Size = UDim2.new(0, 120, 0, 120)
buttonFrame.Position = UDim2.new(1, -140, 0, 20)
buttonFrame.BackgroundTransparency = 1
buttonFrame.Parent = macroGui

local button = Instance.new("ImageButton")
button.Name = "MacroButton"
button.Image = "rbxassetid://71767288014463"
button.Size = UDim2.new(0, 100, 0, 100)
button.Position = UDim2.new(0, 10, 0, 10)
button.BackgroundTransparency = 1
button.Parent = buttonFrame

local dragging, dragStart, startPos

button.InputBegan:Connect(function(input)
    if input.UserInputType == Enum.UserInputType.Touch or input.UserInputType == Enum.UserInputType.MouseButton1 then
        dragging = true
        dragStart = input.Position
        startPos = button.Position
        input.Changed:Connect(function()
            if input.UserInputState == Enum.UserInputState.End then
                dragging = false
            end
        end)
    end
end)

button.InputChanged:Connect(function(input)
    if input.UserInputType == Enum.UserInputType.Touch or input.UserInputType == Enum.UserInputType.MouseMovement then
        if dragging then
            local delta = input.Position - dragStart
            button.Position = UDim2.new(startPos.X.Scale, startPos.X.Offset + delta.X, startPos.Y.Scale, startPos.Y.Offset + delta.Y)
        end
    end
end)

button.MouseButton1Click:Connect(function()
    if not Script.Settings.Marco then
        Script.Settings.Marco = { Enabled = false, Connection = nil, Delay = 0.025 }
    end

    Script.Settings.Marco.Enabled = not Script.Settings.Marco.Enabled

    if Script.Settings.Marco.Enabled then
        Script.Functions.EnableShiftlock()
    else
        Script.Functions.DisableShiftlock()
    end
end)


utilities:AddToggle('macro', {
    Text = 'Enable Macro',
    Default = false,
    Callback = function(Value)
        Script.Settings.Enabled = Value
    end
})

utilities:AddSlider('macrodelay', {
    Text = 'Delay',
    Default = 0.025,
    Min = 0.01,
    Max = 0.1,
    Rounding = 3,
    Compact = false,
    Callback = function(Value)
        Script.Settings.Marco.Delay = Value
    end
})

utilities:AddButton({
    Text = "Load Macro Button",
    Func = function()
        Script.Settings.ShowMacroGui = not Script.Settings.ShowMacroGui
        macroGui.Enabled = Script.Settings.ShowMacroGui
    end,
    DoubleClick = false,
    Tooltip = nil
})

local TimeElapsed = 0

RunService.RenderStepped:Connect(LPH_NO_VIRTUALIZE(function(s)
    if not Script.Settings.Enabled or not Script.Settings.Marco or not Script.Settings.Marco.Delay then return end

    TimeElapsed = TimeElapsed + s
    if TimeElapsed >= Script.Settings.Marco.Delay then
        if Script.Settings.Marco.Enabled then
            if not Script.Settings.Marco.Connection then
                Script.Settings.Marco.Connection = RunService.RenderStepped:Connect(function()
                    Script.Functions.EnableShiftlock()
                end)
            elseif Script.Settings.Marco.Connection then
                Script.Functions.DisableShiftlock()
            end
        end
        TimeElapsed = 0
    end
end))

autoair:AddToggle('autoair', {
    Text = 'Auto Air',
    Default = false, 
    Tooltip = nil,

    Callback = function(Value)
        KingVon.Random.AutoAir = Value
    end
})
autoair:AddSlider('autoairdelay', {
    Text = 'Delay',
    Default = 0.13,
    Min = 0,
    Max = 1,
    Rounding = 2,
    Compact = false,

    Callback = function(Value)
        KingVon.Random.AutoAirDelay = Value
            end
})
selfvis:AddToggle('forcefield', {
    Text = 'Forcefield',
    Default = false, 
    Tooltip = nil,

    Callback = function(Value)
        ForcefieldSettings.Enabled = Value
    end
})
selfvis:AddLabel('Forcefield color'):AddColorPicker('ColorPicker', {
    Default = Color3.new(1, 1, 1),
    Title = 'Forcefield color',
    Transparency = nil,

    Callback = function(Value)
        ForcefieldSettings.Color = Value
    end
})



local cloneref = getgenv().cloneref or function(...) return ... end

local Game = cloneref(Game)

local RunService = Game:GetService("RunService")
local Players = Game:GetService("Players")

local LocalPlayer = Players.LocalPlayer
local LocalCharacter = LocalPlayer.Character or LocalPlayer.CharacterAdded:Wait()
local LocalHumanoid = LocalCharacter:FindFirstChildOfClass("Humanoid") or LocalCharacter:FindFirstChildWhichIsA("Humanoid") or LocalCharacter:WaitForChild("Humanoid")
local LocalRootPart = LocalHumanoid.RootPart or LocalCharacter:WaitForChild("HumanoidRootPart")

local hcswitchEnabled = false 

local hcswitchyy = hcswitch:AddButton({
    Text = 'Enable switch',
    Func = function()
        hcswitchEnabled = not hcswitchEnabled
    end,
    DoubleClick = false,
    Tooltip = nil
})

LocalPlayer.CharacterAdded:Connect(function(Character)
    LocalCharacter = Character
    LocalHumanoid = LocalCharacter:FindFirstChildOfClass("Humanoid") or LocalCharacter:FindFirstChildWhichIsA("Humanoid") or LocalCharacter:WaitForChild("Humanoid")
    LocalRootPart = LocalHumanoid.RootPart or LocalCharacter:WaitForChild("HumanoidRootPart")
end)

RunService.PostSimulation:Connect(function(DeltaTime)
    if hcswitchEnabled and LocalCharacter and LocalHumanoid and LocalRootPart then
        local Gun = LocalCharacter:FindFirstChildOfClass("Tool")
        if Gun and Gun:FindFirstChild("GunData") then
            local Module = require(Gun:FindFirstChild("GunData"))
            Module["slowdown_time"] = 1
            Module["cooldown"] = 0
        end
    end
end)

hcswitch:AddButton({
    Text = "Load switch button",
    Func = function()
       local Players = game:GetService("Players")
local RunService = game:GetService("RunService")

local Client = Players.LocalPlayer
local scriptEnabled = true
local spamEnabled = false

if scriptEnabled then
    local drank = Instance.new("ScreenGui")
    drank.ResetOnSpawn = false
    drank.Parent = Client:WaitForChild("PlayerGui")

    local toggleButton = Instance.new("ImageButton")
    toggleButton.Size = UDim2.new(0, 150, 0, 50)
    toggleButton.Position = UDim2.new(0.5, -75, 0.8, 0)
    toggleButton.Image = "rbxassetid://75971202867459"
    toggleButton.Parent = drank

    local dragging = false
    local dragStart, startPos

    toggleButton.InputBegan:Connect(function(input)
        if input.UserInputType == Enum.UserInputType.Touch or input.UserInputType == Enum.UserInputType.MouseButton1 then
            dragging = true
            dragStart = input.Position
            startPos = toggleButton.Position
        end
    end)

    toggleButton.InputChanged:Connect(function(input)
        if dragging and (input.UserInputType == Enum.UserInputType.Touch or input.UserInputType == Enum.UserInputType.MouseMovement) then
            local delta = input.Position - dragStart
            toggleButton.Position = UDim2.new(startPos.X.Scale, startPos.X.Offset + delta.X, startPos.Y.Scale, startPos.Y.Offset + delta.Y)
        end
    end)

    toggleButton.InputEnded:Connect(function(input)
        if input.UserInputType == Enum.UserInputType.Touch or input.UserInputType == Enum.UserInputType.MouseButton1 then
            dragging = false
        end
    end)

    local function spamTool()
        local tool = Client.Character and Client.Character:FindFirstChildOfClass("Tool")
        if tool and tool:IsA("Tool") then
            tool:Activate()
        end
    end

    toggleButton.MouseButton1Click:Connect(function()
        spamEnabled = not spamEnabled
        toggleButton.ImageColor3 = spamEnabled and Color3.fromRGB(0, 255, 0) or Color3.fromRGB(255, 0, 0)
        if spamEnabled then
            spawn(function()
                while spamEnabled do
                    spamTool()
                    RunService.Heartbeat:Wait()
                end
            end)
        end
    end)
end
    end,
    DoubleClick = false,
    Tooltip = nil
})



-- UI Settings
local MenuGroup = Tabs['UI Settings']:AddLeftGroupbox('Menu')

-- I set NoUI so it does not show up in the keybinds menu
MenuGroup:AddButton('Unload', function() Library:Unload() end)
MenuGroup:AddLabel('Menu bind'):AddKeyPicker('MenuKeybind', { Default = 'End', NoUI = true, Text = 'Menu keybind' })


Library.ToggleKeybind = Options.MenuKeybind -- Allows you to have a custom keybind for the menu

-- Addons:
-- SaveManager (Allows you to have a configuration system)
-- ThemeManager (Allows you to have a menu theme system)

-- Hand the library over to our managers
ThemeManager:SetLibrary(Library)
SaveManager:SetLibrary(Library)

-- Ignore keys that are used by ThemeManager.
-- (we dont want configs to save themes, do we?)
SaveManager:IgnoreThemeSettings()

-- Adds our MenuKeybind to the ignore list
-- (do you want each config to have a different menu key? probably not.)
SaveManager:SetIgnoreIndexes({ 'MenuKeybind' })

-- use case for doing it this way:
-- a script hub could have themes in a global folder
-- and game configs in a separate folder per game
ThemeManager:SetFolder('MyScriptHub')
SaveManager:SetFolder('MyScriptHub/specific-game')

-- Builds our config menu on the right side of our tab
SaveManager:BuildConfigSection(Tabs['UI Settings'])

-- Builds our theme menu (with plenty of built in themes) on the left side
-- NOTE: you can also call ThemeManager:ApplyToGroupbox to add it to a specific groupbox
ThemeManager:ApplyToTab(Tabs['UI Settings'])

-- You can use the SaveManager:LoadAutoloadConfig() to load a config
-- which has been marked to be one that auto loads!
SaveManager:LoadAutoloadConfig()
