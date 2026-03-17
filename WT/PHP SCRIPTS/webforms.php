<?php
if (isset($_GET['name']) && isset($_GET['email'])) {
    echo '<h2>Thank you for submitting your request!</h2>';
    echo '<h3>Here are the details you submitted:</h3>';
    echo 'Name: ' . htmlspecialchars($_GET['name']) . '<br>';
    echo 'Email: ' . htmlspecialchars($_GET['email']) . '<br>';
} else {
    echo '<h2>Error: Missing required fields</h2>';
    echo '<p>Please provide both name and email.</p>';
}
?>