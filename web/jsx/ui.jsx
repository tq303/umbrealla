import React from 'react';
import ReactDOM from 'react-dom';
import Processing from 'processing-js';

require('../styles/ui.scss');

class UI extends React.Component {
    constructor(props) {
        super(props);
        window.console.log(Processing);
    }
    render() {
        return <h1>This is the interface.</h1>
    }
}

ReactDOM.render(<UI/>, document.getElementById('ui'));
