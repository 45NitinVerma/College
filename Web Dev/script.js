const nameInput = document.getElementById('name');
const passwordInput = document.getElementById('password');
const emailInput = document.getElementById('email');
const phoneInput = document.getElementById('phone');
const form = document.querySelector('.form');

form.addEventListener('submit', (event) => {
  event.preventDefault();

  let isValid = true;

  // Validate name
  if (nameInput.value.length < 6 || nameInput.validity.valid) {
    isValid = false;
    nameInput.classList.add('invalid');
    alert('Name should contain only alphabets and be at least 6 characters long.');
  } else {
    nameInput.classList.remove('invalid');
  }

  // Validate password
  if (passwordInput.value.length < 6) {
    isValid = false;
    passwordInput.classList.add('invalid');
    alert('Password should be at least 6 characters long.');
  } else {
    passwordInput.classList.remove('invalid');
  }

  // Validate email
  if (emailInput.validity.valid) {
    isValid = false;
    emailInput.classList.add('invalid');
    alert('Please enter a valid email address.');
  } else {
    emailInput.classList.remove('invalid');
  }

  // Validate phone number
  if (phoneInput.validity.valid) {
    isValid = false;
    phoneInput.classList.add('invalid');
    alert('Phone number should contain 10 digits only.');
  } else {
    phoneInput.classList.remove('invalid');
  }

  if (isValid) {
    // Submit the form
    form.submit();
  }
});