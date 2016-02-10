import React      from 'react';
import ReactDOM   from 'react-dom';
import Processing from 'processing-js';

require('../../styles/ui.scss');

import Cycle from './Cycle';
import Led   from './Led';

class UI extends React.Component {
    render() {
        return (
            <div>
                <Cycle/>
                <Led/>
            </div>
        )
    }
}

ReactDOM.render(<UI/>, document.getElementById('ui'));
