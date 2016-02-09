import React from 'react';
import ReactDOM from 'react-dom';

require('../styles/ui.scss');

class UI extends React.Component {
    render() {
        return <h1>This is the interface.</h1>
    }
}

ReactDOM.render(<UI/>, document.getElementById('ui'));
