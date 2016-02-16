import React from 'react';

import CameraPosition from './CameraPosition';
import CameraRotation from './CameraRotation';

require('../../styles/ui-3d.scss');

class UI3D extends React.Component {
    render() {
        return (
            <div>
                <CameraPosition umbrella={ this.props.umbrella } />
                <CameraRotation umbrella={ this.props.umbrella } />
            </div>
        )
    }
}

UI3D.propTypes = {
    umbrella: React.PropTypes.object.isRequired
};

export default UI3D;
