import THREE from 'three';

class Umbrella {
    constructor() {
        // scene and camera
        this.scene    = new THREE.Scene();
        this.camera   = new THREE.PerspectiveCamera( 75, 480 / 320, 1, 10000 );
        this.camera.position.z = 1000;

        // geometry and material
        this.geometry = new THREE.BoxGeometry( 200, 200, 200 );
        this.material = new THREE.MeshBasicMaterial( { color: 0xff0000, wireframe: true } );
        this.mesh     = new THREE.Mesh( this.geometry, this.material );

        // add geometry to scene
        this.scene.add( this.mesh );

        // initialize renderer
        this.renderer = new THREE.WebGLRenderer();
        this.renderer.setSize( 480, 320 );

        document.getElementById('umbrella').appendChild( this.renderer.domElement );

        this.animate();
    }
    animate() {
        requestAnimationFrame( () => this.animate() );
        this.mesh.rotation.x += 0.01;
        this.mesh.rotation.y += 0.02;
        this.renderer.render( this.scene, this.camera );
    }
}

export default Umbrella;
