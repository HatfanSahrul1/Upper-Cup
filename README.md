# Tugas Akhir Mata Kuliah Design Pattern
## Oscar Javier Abdullah	(5223600001)</br>Hatfan Sahrul Ramadhan	(5223600004)
Proyek ini merupakan implementasi tugas akhir untuk mata kuliah **Design Pattern**. Game dikembangkan menggunakan bahasa C++ dengan bantuan library **raylib** untuk keperluan grafis, serta menerapkan <i>Design Patterns</i> seperti:

- Singleton
- Factory
- State

## 📦 Struktur Proyek
```bash
project-root/
│
├── game/
│ └── src/ 
│ └── include/ 
│
├── image/ # Gambar/asset (pesawat.png, dll)
│
├── build/ # Folder hasil build (berisi game.exe)
│
├── CMakeLists.txt # Konfigurasi build (CMake)
│
└── README.md # Dokumentasi
```

## ▶️ Cara Menjalankan

**Build proyek dengan CMake**
```bash
   mkdir build
   cd build
   cmake ..
   mingw32-make
   game.exe
```
## 🎮 Gameplay
![Demo Gameplay](UpperCup.gif)

## Diagram UML
<!-- ![Mermaid Diagram](https://mermaidviewer.com/api/diagrams/cmbglq27p004wkc1cuf62xv60/image) -->
```mermaid
classDiagram
    %% Main Game Loop
    class GameLoop {
        -bool isRunning
        -GameManager* game_manager_
        +Run() void
        +Update() void
        +Render() void
        +Stop() void
    }

    %% Singleton Pattern - Game Manager
    class GameManager {
        -static GameManager* instance
        -int local_state_
        -int score_
        -Camera2D camera_
        -ObstacleManager obs_manager_
        -shared_ptr~IGameState~ currentState_
        -shared_ptr~Cup~ cup_
        -shared_ptr~Wall~ top_
        -shared_ptr~Wall~ bottom_
        -GameManager()
        +GetInstance()$ GameManager*
        +ProccesInput() void
        +RenderObjects() void
        +ChangeState(newState) void
        +GetCup() shared_ptr~Cup~
        +GetCamera() Camera2D*
        +ResetCup() void
        +ResetCamera() void
        +SetScore(i) void
        +GetScore() int
        +GetObstacleManager() ObstacleManager*
    }

    %% State Pattern
    class IGameState {
        <<interface>>
        +Enter()* bool
        +MainState()* bool
        +Exit()* bool
        +Render()* void
    }

    class HomeScreen {
        +Enter() bool
        +MainState() bool
        +Exit() bool
        +Render() void
    }

    class Playing {
        -float flashTimer_
        -bool drawFlash_
        +Enter() bool
        +MainState() bool
        +Exit() bool
        +Render() void
    }

    class GameOver {
        +Enter() bool
        +MainState() bool
        +Exit() bool
        +Render() void
    }

    %% Renderable Base Class
    class Renderable {
        <<abstract>>
        +Renderable()
        +Render()* void
        +AssignObject() void
    }

    %% Game Objects
    class Cup {
        -Vector2 position_
        -float velocityY_
        -Rectangle collider_
        -Texture2D cupTexture_
        -GRAVITY float
        -LIFT float
        -MAX_HEIGHT float
        -GROUND_Y float
        -WIDTH float
        -HEIGHT float
        +Cup()
        +Cup(startPos)
        +~Cup()
        +Render() void
        +Floating(isJetpackActive) void
        +MoveAside() void
        +GetPosition() Vector2
        +GetCollider() Rectangle*
        +SetPosition(pos) void
    }

    class Obstacle {
        -SIZE float
        -Vector2 headPosition_
        -float length_
        -float distance_
        +Obstacle()
        +Obstacle(initPos, length, distance)
        +Render() void
        +Move(deltaTime) void
        +GetPosition() Vector2
        +SetPositionBehindX(newX) void
        +GetColliders() vector~Rectangle~
        +CheckCollision(other) bool
    }

    class Wall {
        -Vector2 position_
        -float height_
        -WIDTH float
        +Wall()
        +Wall(pos, height)
        +Render() void
    }

    %% Factory Pattern
    class CupFactory {
        <<utility>>
        +CreateCup(position)$ shared_ptr~Cup~
    }

    class ObstacleFactory {
        <<utility>>
        +CreateObstacle(initPos, length, distance)$ shared_ptr~Obstacle~
    }

    class WallFactory {
        <<utility>>
        +CreateWall(type, screenHeight)$ shared_ptr~Wall~
    }

    %% Obstacle Manager
    class ObstacleProp {
        <<struct>>
        +Vector2 pos
        +int length
        +int dist
    }

    class ObstacleManager {
        -vector~ObstacleProp~ obs_init_
        -vector~shared_ptr~Obstacle~~ obstacles_
        +CreateObstacle() void
        +RenderObstacles() void
        +CycleObstalce(cameraX) void
        +IsCollide(other) bool
    }

    %% Relationships
    GameLoop --> GameManager : uses
    GameManager *-- ObstacleManager : contains
    GameManager *-- Cup : contains
    GameManager *-- Wall : contains
    GameManager o-- IGameState : manages

    IGameState <|.. HomeScreen : implements
    IGameState <|.. Playing : implements
    IGameState <|.. GameOver : implements

    Renderable <|-- Cup : extends
    Renderable <|-- Obstacle : extends
    Renderable <|-- Wall : extends

    CupFactory ..> Cup : creates
    ObstacleFactory ..> Obstacle : creates
    WallFactory ..> Wall : creates

    ObstacleManager --> ObstacleProp : uses
    ObstacleManager --> Obstacle : manages
    ObstacleManager ..> ObstacleFactory : uses

    HomeScreen ..> Playing : transitions to
    Playing ..> GameOver : transitions to
    GameOver ..> Playing : transitions to

    %% Notes for Design Patterns
    note for GameManager "Singleton Pattern"
    note for IGameState "State Pattern"
    note for CupFactory "Factory Pattern"
```
