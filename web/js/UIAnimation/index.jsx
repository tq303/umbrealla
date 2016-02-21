import React from 'react';

require('../../styles/ui-animation.scss');

import Cycle  from './Cycle';
import Lights from './Lights';

class UIAnimation extends React.Component {
    render() {
        return (
            <div>
                <Cycle ledCount={ this.props.ledCount } stripCount={ this.props.stripCount }/>
                <Lights/>
            </div>
        )
    }
}

UIAnimation.propTypes = {
    ledCount: React.PropTypes.number.isRequired,
    stripCount: React.PropTypes.number.isRequired
};

export default UIAnimation;
