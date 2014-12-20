#include <libs/tet/include/gazeapi.h>
#include <idlib/containers/List.h>

// --- idGaze definition
class idGaze : public gtl::IGazeListener
{
    public:
        idGaze();
        ~idGaze();
    private:
        // IGazeListener
        void on_gaze_data( gtl::GazeData const & gaze_data );
    private:
        gtl::GazeApi m_api;
        idList< std::pair<float, float> > m_gazePoints;

};
