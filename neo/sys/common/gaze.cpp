#include "gaze.h"

// --- MyGaze implementation
idGaze::idGaze()
{
    // Connect to the server in push mode on the default TCP port (6555)
    if( m_api.connect( true ) )
    {
        // Enable GazeData notifications
        m_api.add_listener( *this );
        common->Warning( "Connected to The Eye Tribe server" );
    }
}

idGaze::~idGaze()
{
    m_api.remove_listener( *this );
    m_api.disconnect();
}

void idGaze::on_gaze_data( gtl::GazeData const & gaze_data )
{
    if( gaze_data.state & gtl::GazeData::GD_STATE_TRACKING_GAZE )
    {
        gtl::Point2D const & smoothedCoordinates = gaze_data.avg;

//        common->Printf( "New gaze coordinate : %.2f %.2f\n",
//                        smoothedCoordinates.x,
//                        smoothedCoordinates.y );

        // Move GUI point, do hit-testing, log coordinates, etc.
        m_gazePoints.Append( std::make_pair<float,float>(smoothedCoordinates.x,
                                                         smoothedCoordinates.y));
    }

    // Restrain the list to the last 10 gaze points
    // FIXME: Ben - not sure that we pick the last 10 here..
    m_gazePoints.Resize( std::min(10, int(m_gazePoints.Size())) );
}
