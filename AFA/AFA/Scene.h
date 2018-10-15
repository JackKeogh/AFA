/// <summary>
/// This is an abstract class for scenes to inherit from.
/// </summary>

class Scene
{
public:
	// Destructor
	virtual ~Scene() {};

	/// <summary>
	/// Update
	/// 
	/// Updates the scene class.
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	/// Render
	/// 
	/// Renders the scene class.
	/// </summary>
	virtual void Render() = 0;

	/// <summary>
	/// Event
	/// 
	/// Handles the input events for the scene class.
	/// </summary>
	virtual void Event() = 0;

	/// <summary>
	/// Running
	/// 
	/// Checks if the scene is running.
	/// </summary>
	/// <returns>A bool value.</returns>
	virtual bool Running() = 0;

	/// <summary>
	/// Initialise
	/// 
	/// initialises the scene.
	/// </summary>
	virtual void Initialise() = 0;

	/// <summary>
	/// Load Level
	/// 
	/// Loads the next level.
	/// </summary>
	virtual void LoadLevel() = 0;

private:
	bool m_running;
};