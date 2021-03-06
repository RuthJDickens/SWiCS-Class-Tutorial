#pragma once

class GameObject
{
public:

    enum Type
    {
        OBJ_NONE = -1,
        OBJ_PLAYER = 0,
        OBJ_SAUCER,
        OBJ_LASER,
        OBJ_ALL = 999
    };

    //Constructors and Destructor
    GameObject();
    GameObject( Point2f pos );
    virtual ~GameObject();

    //Pure Virtual Functions
    virtual void Update( GameState& state ) = 0;
    virtual void Draw( GameState& gState ) = 0;

    //Inherited Getters and Setters
    void SetPosition( Point2f pos ) { m_pos = pos; }
    Point2f GetPosition() const { return m_pos; };

    void SetVelocity( Vector2f vel ) { m_velocity = vel; }
    Vector2f GetVelocity() const { return m_velocity; };

    void SetDrawOrder( int drawOrder ) { m_drawOrder = drawOrder; }
    int GetDrawOrder() const { return m_drawOrder; };

    void SetUpdateOrder( int updateOrder ) { m_updateOrder = updateOrder; }
    int GetUpdateOrder() const { return m_updateOrder; };

    //Static methods = general methods, not called on specific objects
    static int GetObjectCount( Type eType );
    static int GetObjectList( GameObject::Type eType, std::vector< GameObject* >& vList );

    static void UpdateAll( GameState& state );
    static void DrawAll( GameState& state );
    static void DestroyAll();

protected:
    //For sorting
    static bool DrawOrder( const GameObject* a, const GameObject* b ) { return a->m_drawOrder > b->m_drawOrder; }
    static bool UpdateOrder( const GameObject* a, const GameObject* b ) { return a->m_updateOrder > b->m_updateOrder; }

    //Inherited variables
    Type m_type{ OBJ_NONE };
    bool m_active{ true };
    Point2f m_pos{ 0, 0 };
    Vector2f m_velocity{ 0, 0 };
    int m_spriteId{ -1 };

    int m_drawOrder{ 0 };
    int m_updateOrder{ 0 };

    static std::vector< GameObject* > s_vUpdateList;
    static std::vector< GameObject* > s_vDrawList;

};

