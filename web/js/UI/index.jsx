import React from 'react';

require('../../styles/ui.scss');

import Cycle from './Cycle';
import Led   from './Led';

class UI extends React.Component {
    render() {
        return (
            <div>
                <Cycle ledCount={ this.props.ledCount } stripCount={ this.props.stripCount }/>
                <Led/>
            </div>
        )
    }
}

UI.propTypes = {
    ledCount: React.PropTypes.number.isRequired,
    stripCount: React.PropTypes.number.isRequired
};

export default UI;
